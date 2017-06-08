<?php
/**
 * Created by PhpStorm.
 * User: Styl3R
 * Date: 5/30/17
 * Time: 5:43 AM
 */

include "Connection/Database.inc";
include "Account/AccountManager.inc";

$accManager = new AccountManager();

$user = "stylr11";

$q = $accManager->userExists($user);
if ($q) {
    $details = $accManager->getDetails("serikov21");

    echo "Your account balance is: $" . $details['balance'];
    echo "\n";
    echo "Your account password is: " . $details['pass'];
    echo "\n";
    echo "Your account Number is: " . $details['acc'];
} else {
    echo $user . " is an incorrect username";
}
