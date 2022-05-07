FROM debian:buster

LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="nginx"

# install nginx, openssl
RUN apt-get update -y && apt-get install -y nginx && apt-get install openssl

# copy default file for network php
RUN rm /etc/nginx/sites-available/default
COPY ./conf/default /etc/nginx/sites-available/
RUN perl -pi -e 's/localhost/\$DOMAIN_NAME/g' /etc/nginx/sites-available/default
COPY ./tools/soum.crt /etc/ssl/certs
COPY ./tools/soum.key /etc/ssl/private

# nginx foreground daemon mode
RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

# port open 443 https
EXPOSE 443

#execute nginx
CMD nginx
