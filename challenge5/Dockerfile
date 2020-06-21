# Use an official Python runtime as a parent image
FROM debian:buster

ENV DEBIAN_FRONTEND noninteractive
ENV TZ=America/New_York
# Update
RUN apt-get update --fix-missing && apt-get -y upgrade

# System deps
RUN apt-get install -y xinetd

RUN groupadd -r chal5 && useradd -r -g chal5 chal5
RUN mkdir /home/chal5

ADD config/ihack2020.xinetd /etc/xinetd.d/chal5
ADD config/run_xinetd.sh /etc/run_xinetd.sh
ADD run_chal5.sh /home/chal5/run_chal5.sh

ADD chal5.c /home/chal5/chal5.c
ADD chal5 /home/chal5/chal5
ADD flag5.txt /home/chal5/flag5.txt

RUN chown -R chal5 /home/chal5
RUN chmod 750 /home/chal5/chal5
RUN chmod 750 /home/chal5/run_chal5.sh
RUN chmod 777 /home/chal5/flag5.txt

RUN chmod 700 /etc/run_xinetd.sh

RUN service xinetd restart
