<?php

$fh = fopen($argv[1], "r");
while (true) {

	$sLine = trim(fgets($fh));
	if(empty($sLine))
		break;

	$aTimes = explode(" ", $sLine);
	$aTimes[0] = strtotime($aTimes[0]);
	$aTimes[1] = strtotime($aTimes[1]);

	if($aTimes[0] > $aTimes[1]){
		$aTimes[0] -= $aTimes[1];
	}else{
		$aTimes[0] = $aTimes[1] - $aTimes[0];
	}

	$hours = (($aTimes[0] / 60 / 60) % 60);
	$minutes = (($aTimes[0] / 60) % 60);
	$seconds = ($aTimes[0] % 60);

	echo ($hours < 10 ? "0" . $hours : $hours) . ":" . ($minutes < 10 ? "0" . $minutes : $minutes) . ":" . ($seconds < 10 ? "0" . $seconds : $seconds) . "\n";

}

?>
