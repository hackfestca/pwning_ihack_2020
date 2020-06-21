# Use an official Python runtime as a parent image
FROM debian:buster

ENV DEBIAN_FRONTEND noninteractive

# Update
RUN apt-get update --fix-missing && apt-get -y upgrade

# System deps
RUN apt-get install -y xinetd

RUN groupadd -r chal3 && useradd -r -g chal3 chal3
RUN mkdir /home/chal3

ADD config/ihack2020.xinetd /etc/xinetd.d/chal3
ADD config/run_xinetd.sh /etc/run_xinetd.sh
ADD run_chal3.sh /home/chal3/run_chal3.sh

ADD chal3.c /home/chal3/chal3.c
ADD chal3 /home/chal3/chal3
ADD flag3.txt /home/chal3/flag3.txt

RUN chown -R chal3 /home/chal3
RUN chmod 750 /home/chal3/chal3
RUN chmod 750 /home/chal3/run_chal3.sh
RUN chmod 777 /home/chal3/flag3.txt

RUN chmod 700 /etc/run_xinetd.sh

RUN service xinetd restart
