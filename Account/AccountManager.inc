<?php
/**
 * Created by PhpStorm.
 * User: Styl3R
 * Date: 5/30/17
 * Time: 5:49 AM
 */

class AccountManager
{

    /**
     * AccountManager constructor.
     * @param bool $accNum
     */
    public function __construct($accNum = false)
    {

    }

    public function createAccount($user, $pass)
    {
        $id = rand(1000, 9999);
        $acc = '001' . rand(12345678, 99999999);
        $bal = 0;
        $date = time();

        $sql = "INSERT INTO `bank` VALUES({$id}, '{$user}', '{$pass}', '{$acc}', {$bal}, '{$date}')";

        $result = Query::run($sql);

        if ($result) {
            return true;
        } else {
            return false;
        }
    }

    public function getDetails($user)
    {
        $sql = "SELECT * FROM `bank` WHERE `user` = '{$user}'";

        $result = Query::run($sql);

        $rows = $result->fetch_assoc();

        return $rows;
    }

}