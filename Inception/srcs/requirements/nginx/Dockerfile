FROM debian:buster

ARG CERTS
ARG KEYS

LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="nginx"

RUN apt-get update -y && apt-get install -y nginx && apt-get install openssl

RUN rm /etc/nginx/sites-available/default
COPY ./conf/default /etc/nginx/sites-available/
COPY $CERTS /etc/ssl/certs
COPY $KEYS /etc/ssl/private

RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

EXPOSE 443

CMD nginx
