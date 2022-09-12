FROM debian:buster

ARG MYSQL_HOST
ARG MYSQL_PORT
ARG MYSQL_ROOT
ARG MYSQL_ROOT_PASSWORD
ARG MYSQL_PASSWORD
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG DOMAIN_NAME
ARG WP_TITLE
ARG WP_ADMIN
ARG WP_ADMIN_EMAIL
ARG WP_ADMIN_PW
ARG WP_USER
ARG WP_USER_EMAIL
ARG WP_USER_PW
ARG WP_PORT


LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="wordpress + php-fpm"

RUN apt-get update -y && apt-get install -y php-fpm && apt-get install -y php-mysql && apt-get install -y wget && apt-get install -y mariadb-client && apt-get install -y vim

COPY ./tools/conf.sh /
RUN chmod +x /conf.sh

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

CMD /conf.sh
