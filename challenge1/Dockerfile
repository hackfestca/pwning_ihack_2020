# Use an official Python runtime as a parent image
FROM debian:buster

ENV DEBIAN_FRONTEND noninteractive

# Update
RUN apt-get update --fix-missing && apt-get -y upgrade

# System deps
RUN apt-get install -y xinetd

RUN groupadd -r chal1 && useradd -r -g chal1 chal1
RUN mkdir /home/chal1

ADD config/ihack2020.xinetd /etc/xinetd.d/chal1
ADD config/run_xinetd.sh /etc/run_xinetd.sh
ADD run_chal1.sh /home/chal1/run_chal1.sh

ADD chal1.c /home/chal1/chal1.c
ADD chal1 /home/chal1/chal1

RUN chown -R chal1 /home/chal1
RUN chmod 750 /home/chal1/chal1
RUN chmod 750 /home/chal1/run_chal1.sh

RUN chmod 700 /etc/run_xinetd.sh

RUN service xinetd restart
