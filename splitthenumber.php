<?php

// TIME WRAPPER ----------------------------------------------------------------
$lStartTime = microtime(true);
// -----------------------------------------------------------------------------

$fh = fopen($argv[1], "r");
while (true) {
	$sLine = trim(fgets($fh));
	if(empty($sLine))
		break;
	$aRules = explode(" ", $sLine);
	$lPos = strpos($aRules[1], "+");
	if($lPos !== false){
		echo (((int)substr($aRules[0], 0, $lPos)) + ((int)substr($aRules[0], $lPos)) . "\n");
	}else{
		$lPos = strpos($aRules[1], "-");
		if($lPos !== false){
			echo (((int)substr($aRules[0], 0, $lPos)) - ((int)substr($aRules[0], $lPos))) . "\n";
		}else{
			echo $aRules[0] . "\n";
		}
	}
}

// TIME WRAPPER ----------------------------------------------------------------
$lEndTime = microtime(true);
echo "Execution in: " . ($lEndTime - $lStartTime) . "\n";
// -----------------------------------------------------------------------------

?>
