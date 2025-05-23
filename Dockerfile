FROM ubuntu:22.04

RUN apt update \
	&& apt upgrade -y \
	&& apt install -y \
	apt-utils  \
    build-essential  \
    gcc \
    g++ \
    clang \
    cmake  \
    gdb  \
    gdbserver  \
    openssh-server  \
    rsync \
    vim \
    sudo \
    less \
    && apt-get clean

RUN apt-get update  \
    && apt-get install -y \
    libcpprest-dev \
    libboost-all-dev \
    libssl-dev \
    && apt-get clean

# Taken from - https://docs.docker.com/engine/examples/running_ssh_service/#environment-variables
RUN mkdir /var/run/sshd
RUN echo 'root:root' | chpasswd
RUN sed -i 's/^#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -i 's/^#PasswordAuthentication yes/PasswordAuthentication yes/' /etc/ssh/sshd_config

# SSH login fix. Otherwise user is kicked off after login
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"
RUN echo "export VISIBLE=now" >> /etc/profile

# 22 for ssh server. 7777 for gdb server.
EXPOSE 22 7777

# Create dev user with password 'dev'
RUN useradd -ms /bin/bash dev
RUN echo 'dev:dev' | chpasswd
RUN echo '%dev ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

# Upon start, run ssh daemon
CMD ["/usr/sbin/sshd", "-D"]
