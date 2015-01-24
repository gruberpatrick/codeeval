<?php

// TIME WRAPPER ----------------------------------------------------------------
$lStartTime = microtime(true);
// -----------------------------------------------------------------------------

$fh = fopen("testcase", "r");
while (true) {
	$sLine = fgets($fh);
	if(empty($sLine))
		break;
	$aRules = explode(" ", $sLine);
	for($i = 1; $i <= $aRules[2]; $i++){
		if($i > 1)
			echo " ";
		$bFound = false;
		if(($i % $aRules[0]) == 0){
			echo "F";
			$bFound = true;
		}
		if(($i % $aRules[1]) == 0){
			echo "B";
		}else{
			if(!$bFound)
				echo $i;
		}
	}
	echo "\n";
}
//fclose($fh);

// TIME WRAPPER ----------------------------------------------------------------
$lEndTime = microtime(true);
echo "Execution in: " . ($lEndTime - $lStartTime) . "\n";
// -----------------------------------------------------------------------------

?>
