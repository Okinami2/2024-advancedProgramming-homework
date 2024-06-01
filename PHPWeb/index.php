< ? php
    include 'flag.php';
highlight_file(__FILE__);
error_reporting(0);

class Flag {
    public $token;
    public $password;

    public function __construct($a, $b)
    {
        $this->token = $a;
        $this->password = $b;
    }

    public function login()
    {
        return $this->token == = $this->password;
    }
}

if (isset($_GET['pop'])) {
    $pop = unserialize($_GET['pop']);
    $pop->token = md5(mt_rand());
    if ($pop->login()) {
        echo $flag;
    }
}
?>