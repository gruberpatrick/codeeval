<?php

// TIME WRAPPER ----------------------------------------------------------------
$lStartTime = microtime(true);
// -----------------------------------------------------------------------------

$fh = fopen("testcase", "r");
while (true) {
	$sLine = trim(fgets($fh));
	if(empty($sLine))
		break;
	if(strlen($sLine) <= 55){
		echo $sLine . "\n";
	}else{
		$sLine = substr($sLine, 0, 40);
		$lSpace = strripos($sLine, " ");
		if(!$lSpace){
			echo $sLine . "... <Read More>\n";
		}else{
			echo trim(substr($sLine, 0, $lSpace)) . "... <Read More>\n";
		}
	}
}
//fclose($fh);

// TIME WRAPPER ----------------------------------------------------------------
$lEndTime = microtime(true);
echo "Execution in: " . ($lEndTime - $lStartTime) . "\n";
// -----------------------------------------------------------------------------

?>
