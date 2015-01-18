<?php

	$fh = fopen($argv[1], "r");
	while (true) {

		$sLine = trim(fgets($fh));
		if(empty($sLine))
			break;

		$aParts = explode(";", $sLine);
		$aWords = explode(" ", $aParts[0]);
		$aOrder = explode(" ", $aParts[1]);

		unset($aParts);

		for($i = 0; $i < count($aWords); $i++){
			@$aParts[$aOrder[$i]] = $aWords[$i];
		}

		unset($aOrder);

		for($i = 1; $i <= count($aParts); $i++){
			if($i > 1)
				echo " ";
			if(isset($aParts[$i])){
				echo $aParts[$i];
			}else{
				echo $aWords[count($aWords) - 1];
			}
		}

		echo "\n";

	}

?>
