<?php

// TIME WRAPPER ----------------------------------------------------------------
$lStartTime = microtime(true);
// -----------------------------------------------------------------------------

$fh = fopen("testcase", "r");
while (true) {
	$sLine = fgets($fh);
	if(empty($sLine))
		break;
	echo (int)!($sLine % 2) . "\n";
}
//fclose($fh);

// TIME WRAPPER ----------------------------------------------------------------
$lEndTime = microtime(true);
echo "Execution in: " . ($lEndTime - $lStartTime) . "\n";
// -----------------------------------------------------------------------------

?>
