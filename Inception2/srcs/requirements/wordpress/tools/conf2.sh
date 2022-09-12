#!/bin/bash
mkdir -p /var/run/php
perl -pi -e 's/\/run\/php\/php7.3-fpm.sock/$ENV{"WP_PORT"}/g' /etc/php/7.3/fpm/pool.d/www.conf
wp --allow-root core config --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=172.17.0.2

php-fpm7.3 -F
