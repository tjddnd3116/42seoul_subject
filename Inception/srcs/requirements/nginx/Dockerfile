FROM debian:buster

LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="nginx"

# install nginx, openssl
RUN apt-get update -y && apt-get install -y nginx && apt-get install openssl

# create ssl key for https
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=42Seoul/CN=42.fr" -keyout /etc/ssl/private/soum.key -out /etc/ssl/certs/soum.crt
# copy default file for network php
RUN rm /etc/nginx/sites-available/default
COPY ./conf/default /etc/nginx/sites-available/

# nginx foreground daemon mode
RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

#RUN nginx -t
# port open 443(https)
EXPOSE 443

#execute nginx
CMD nginx
