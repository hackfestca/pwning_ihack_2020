# Use an official Python runtime as a parent image
FROM debian:buster

ENV DEBIAN_FRONTEND noninteractive

# Update
RUN apt-get update --fix-missing && apt-get -y upgrade

# System deps
RUN apt-get install -y xinetd

RUN groupadd -r chal2 && useradd -r -g chal2 chal2
RUN mkdir /home/chal2

ADD config/ihack2020.xinetd /etc/xinetd.d/chal2
ADD config/run_xinetd.sh /etc/run_xinetd.sh
ADD run_chal2.sh /home/chal2/run_chal2.sh

ADD chal2.c /home/chal2/chal2.c
ADD chal2 /home/chal2/chal2
ADD flag2.txt /home/chal2/flag2.txt

RUN chown -R chal2 /home/chal2
RUN chmod 750 /home/chal2/chal2
RUN chmod 750 /home/chal2/run_chal2.sh
RUN chmod 777 /home/chal2/flag2.txt

RUN chmod 700 /etc/run_xinetd.sh

RUN service xinetd restart
