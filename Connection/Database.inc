<?php
/**
 * Created by PhpStorm.
 * User: Styl3R
 * Date: 5/30/17
 * Time: 5:44 AM
 */

class Database
{
    private $_connection;
    private static $_instance; //The single instance
    private $_host;
    private $_username;
    private $_password;
    private $_database;

    /**
     * Get an instance of the Database
     * @return Database
     */
    public static function getInstance()
    {
        if (!self::$_instance) { // If no instance then make one
            self::$_instance = new self();
        }
        return self::$_instance;
    }

    // Constructor
    private function __construct()
    {

        $this->setHost('192.81.133.218');
        $this->setUsername('cookie');
        $this->setPassword('simpsons');

        $this->setDatabase('cookiejar');

        $this->_connection = new mysqli($this->_host, $this->_username,
            $this->_password, $this->_database);

        // Error handling
        if (mysqli_connect_error()) {
            trigger_error("Failed to connect to MySQL: " . mysqli_connect_error(),
                E_USER_ERROR);
        }
    }

    // Magic method clone is empty to prevent duplication of connection
    private function __clone()
    {
    }

    // Get mysqli connection
    public function getConnection()
    {
        return $this->_connection;
    }

    /**
     * @param string $host
     */
    public function setHost($host)
    {
        $this->_host = $host;
    }

    /**
     * @param string $username
     */
    public function setUsername($username)
    {
        $this->_username = $username;
    }

    /**
     * @param string $password
     */
    public function setPassword($password)
    {
        $this->_password = $password;
    }

    /**
     * @param string $database
     */
    public function setDatabase($database)
    {
        $this->_database = $database;
    }

}

class Query extends Database
{
    /**
     * @param $sql
     * @return bool|mysqli_result
     */
    public static function run($sql)
    {
        return parent::getInstance()->getConnection()->query($sql);
    }

    public static function escape($string)
    {
        return parent::getInstance()->getConnection()->real_escape_string($string);
    }

    public static function err()
    {
        return parent::getInstance()->getConnection()->error;
    }
}