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
        $sql = "SELECT * FROM `bank` WHERE `user` = '{$user}'"; //prepare SQL statement

        $result = Query::run($sql); //execute SQL statement

        $rows = $result->fetch_assoc(); //Get rows from the table from the SQL statement

        return $rows; //return the rows
    }

    public function userExists($user)
    {
        $sql = "SELECT count(*) FROM `bank` WHERE `user` = '{$user}'";

        $result = Query::run($sql);

        $rows = $result->fetch_row();

        if ($rows[0] == 1) {
            return true;
        } else {
            return false;
        }
    }

}//isnt this the end of the class?? why are you creating a function outside the class????

