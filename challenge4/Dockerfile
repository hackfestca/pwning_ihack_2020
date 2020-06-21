# Use an official Python runtime as a parent image
FROM debian:buster

ENV DEBIAN_FRONTEND noninteractive

# Update
RUN apt-get update --fix-missing && apt-get -y upgrade

# System deps
RUN apt-get install -y xinetd

RUN groupadd -r chal4 && useradd -r -g chal4 chal4
RUN mkdir /home/chal4

ADD config/ihack2020.xinetd /etc/xinetd.d/chal4
ADD config/run_xinetd.sh /etc/run_xinetd.sh
ADD run_chal4.sh /home/chal4/run_chal4.sh

ADD chal4.c /home/chal4/chal4.c
ADD chal4 /home/chal4/chal4
ADD flag4.txt /home/chal4/flag4.txt

RUN chown -R chal4 /home/chal4
RUN chmod 750 /home/chal4/chal4
RUN chmod 750 /home/chal4/run_chal4.sh
RUN chmod 777 /home/chal4/flag4.txt

RUN chmod 700 /etc/run_xinetd.sh

RUN service xinetd restart
