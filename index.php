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
$details = $accManager->getDetails("rose22");

echo "Your account balance is: $" . $details['balance'];
echo "\n"; //this is the same thing as echo "<br>";
echo "Your account password is: " . $details['pass'];
echo "\n";
echo "Your account Number is: " . $details['acc'];