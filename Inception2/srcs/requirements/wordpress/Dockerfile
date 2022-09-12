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


LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="wordpress + php-fpm"

RUN apt-get update -y && apt-get install -y php-fpm && apt-get install -y php-mysql && apt-get install -y wget

RUN mkdir -p /var/run/php
RUN perl -pi -e 's/\/run\/php\/php7.3-fpm.sock/$ENV{"WP_PORT"}/g' /etc/php/7.3/fpm/pool.d/www.conf

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
RUN mkdir wordpress
WORKDIR /wordpress
RUN wp core --allow-root download --version=4.2.2 --locale=ko_KR
RUN mkdir -p /var/www/wordpress/
RUN cp -r /wordpress/* /var/www/wordpress/
WORKDIR /var/www/wordpress

# RUN php-fpm7.3 -F


# RUN wp --allow-root core config --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOST
# RUN wp --allow-root core install --uri=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PW --admin_email=$WP_ADMIN_EMAIL
# RUN wp  --allow-root user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PW
#
#CMD php-fpm7.3
# RUN wget https://wordpress.org/latest.tar.gz && tar -zxvf latest.tar.gz
#RUN chown -R root:root /wordpress/*

# COPY ./tools/conf.sh /
# RUN chmod +x /conf.sh
# COPY ./conf/wp-config.php /wordpress
#
# CMD /conf.sh
