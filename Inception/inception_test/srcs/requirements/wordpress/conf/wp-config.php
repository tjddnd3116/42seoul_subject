<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'database' );

/** Database username */
define( 'DB_USER', 'username' );

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
define( 'DB_HOST', 'hostname' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         ']-#/jkycYgsWu6acD<Ki[VTa#|$P*l^nLL={1]_ktlS&L#uSVw3BH<)+?NQ+.kW^');
define('SECURE_AUTH_KEY',  '8cMcaV/raU-~Fm![V.].O<DM?uVm$.2q`2W?rpSmt]K7*TBwRJgNx&}QNDQ?;5 o');
define('LOGGED_IN_KEY',    'MNT|6+|i!tfUCjt_-atP!#gm-|mpxb)^]Jcb54kzhBJ$`Dg?I3gC;L3!m{j`YO0<');
define('NONCE_KEY',        'zeK94KY$y^+Dxm< DvG(_@2H/ 8V{deY;SHNB+.tMCaGngiHI/3byk[a9m<.!p-t');
define('AUTH_SALT',        'Q% .%&Bd:9D6}?p>ZJWrbaR=)V~mg-S=#KI|cmW#y<N%I-bvCi0>/.]H!IW{h-D,');
define('SECURE_AUTH_SALT', '5xb*lyVc1k|^l,XFNN@NDJ^1STj/?9jYVc[F>s&lBkV];7h6Ta+=l+`&4AcbH=<K');
define('LOGGED_IN_SALT',   'O6->L,v*m8fGtO/O`S~U-Zpi#`|Iabck}M(u-~v6dkp2,A+H5KsFr-9[|B7c/IEu');
define('NONCE_SALT',       '|aBz-SIZL9v-r!OW6;{h[GlI5%T-I]H2#6r?d;5$DV&|P+S36|cww?WVD<l^ Jfv');
/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
