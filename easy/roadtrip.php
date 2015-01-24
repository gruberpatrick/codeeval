<?php

$fh = fopen($argv[1], "r");
while (true) {

	$sLine = trim(fgets($fh));
	if(empty($sLine))
		break;

	$aCities = explode(";", $sLine);
	for($i = 0; $i < count($aCities); $i++){
		if($aCities[$i] == ""){
			unset($aCities[$i]);
			continue;
		}
		$aCities[$i] = substr($aCities[$i], strpos($aCities[$i], ",") + 1);
	}

	sort($aCities);

	for($i = 0; $i < count($aCities); $i++){
		if($i > 0){
			echo "," . ($aCities[$i] - $aCities[$i - 1]);
		}else{
			echo $aCities[$i];
		}
	}
	echo "\n";

}

?>
