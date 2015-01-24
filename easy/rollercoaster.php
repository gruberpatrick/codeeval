<?php

// TIME WRAPPER ----------------------------------------------------------------
$lStartTime = microtime(true);
// -----------------------------------------------------------------------------

$fh = fopen($argv[1], "r");
while (true) {
	$sLine = trim(fgets($fh));
	if(empty($sLine))
		break;
	$bCapitalize = true;
	for($i = 0; $i < strlen($sLine); $i++){
		if($bCapitalize)
			echo strtoupper($sLine[$i]);
		else
			echo strtolower($sLine[$i]);
		if((ord($sLine[$i]) > 64 && ord($sLine[$i]) < 91) || (ord($sLine[$i]) > 96 && ord($sLine[$i]) < 123))
			$bCapitalize = !$bCapitalize;
	}
	echo "\n";
}
//fclose($fh);

// TIME WRAPPER ----------------------------------------------------------------
$lEndTime = microtime(true);
echo "Execution in: " . ($lEndTime - $lStartTime) . "\n";
// -----------------------------------------------------------------------------

?>
