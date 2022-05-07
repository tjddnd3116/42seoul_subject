FROM debian:buster

LABEL email="soum@student.42seoul.kr"
LABEL name="soum"
LABEL version="1.0"
LABEL description="wordpress + php-fpm"

# install php-fpm php-mysql wget
RUN apt-get update -y && apt-get install -y php-fpm && apt-get install -y php-mysql && apt-get install -y wget

# download wordpress to wget
RUN wget https://wordpress.org/latest.tar.gz && tar -zxvf latest.tar.gz
RUN chown -R root:root /wordpress/*

# make directory php
RUN mkdir /var/run/php

# insert port conf
RUN perl -p -i -e '$.==37 and print "listen = 9000\n"' /etc/php/7.3/fpm/pool.d/www.conf
COPY ./conf/wp-config.php /wordpress
RUN mkdir -p /var/www/wordpress/
RUN mv /wordpress/* /var/www/wordpress/

CMD php-fpm7.3 -F

EXPOSE 9000
