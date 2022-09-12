#!/bin/bash
mkdir -p /var/run/php
perl -pi -e 's/\/run\/php\/php7.3-fpm.sock/$ENV{"WP_PORT"}/g' /etc/php/7.3/fpm/pool.d/www.conf
mkdir -p /var/www/wordpress/
cd /var/www/wordpress
wp core --allow-root download --version=4.2.2 --locale=ko_KR
mkdir -p /var/www/wordpress/

wp --allow-root core config --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOST
# wp --allow-root core install --url=localhost --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PW --admin_email=$WP_ADMIN_EMAIL
# wp --allow-root theme update --all
# wp --allow-root theme activate twentyfifteen
# wp  --allow-root user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PW
#

php-fpm7.3 -F
