#!/bin/bash
mkdir -p /var/run/php
perl -pi -e 's/\/run\/php\/php7.3-fpm.sock/$ENV{"WP_PORT"}/g' /etc/php/7.3/fpm/pool.d/www.conf
mkdir -p /var/www/wordpress/
cp -r /wordpress/* /var/www/wordpress/
perl -pi -e 's/database/$ENV{"MYSQL_DATABASE"}/g' /var/www/wordpress/wp-config.php
perl -pi -e 's/username/$ENV{"MYSQL_USER"}/g' /var/www/wordpress/wp-config.php
perl -pi -e 's/password/$ENV{"MYSQL_PASSWORD"}/g' /var/www/wordpress/wp-config.php
perl -pi -e 's/hostname/$ENV{"MYSQL_HOST"}/g' /var/www/wordpress/wp-config.php
php-fpm7.3 -F
