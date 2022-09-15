#!/bin/bash

mkdir -p /var/run/php
# nginx와의 통신을 위해 php-fpm listen port 변경
perl -pi -e 's/\/run\/php\/php7.3-fpm.sock/$ENV{"WP_PORT"}/g' /etc/php/7.3/fpm/pool.d/www.conf

# 워드프레스의 중복 설치 및 중복 유저추가를 방지
if [ ! -d "/var/www/wordpress/wp-admin/" ]
then
	mkdir -p /var/www/wordpress/
	cd /var/www/wordpress

	# wp-cli 명령어로 wordpress 다운
	wp --allow-root core download --version=6.0.2 --locale=ko_KR

	# mariadb와의 연결을 위한 wp-config.php파일 생성
	wp --allow-root core config --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOST

	# 워드프레스가 이미 설치되어 있으면 설치하지 않고 유저추가도 하지 않음
	if ! wp --allow-root core is-installed;
	then
		# wp-cli 명령어로 wordpress 설치, admin 생성
		wp --allow-root core install --url=soum.42.fr --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PW --admin_email=$WP_ADMIN_EMAIL

		# wp-cli 명령어로 사용자 추가 및 권한 부여
		wp  --allow-root user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PW
	fi
fi

# php-fpm 데몬으로 실행
php-fpm7.3 -F
