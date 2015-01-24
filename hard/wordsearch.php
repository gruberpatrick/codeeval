<?php

$map = Array(
	Array(Array("A", false), Array("B", false), Array("C",false), Array("E",false)),
	Array(Array("S", false), Array("F", false), Array("C",false), Array("S",false)),
	Array(Array("A", false), Array("D", false), Array("E",false), Array("E",false))
);

function getNeighbors($x, $y, $aMap, $char){
	$res = Array();
	if($y < 0 || $y >= count($aMap) || $x < 0 || $x >= count($aMap[$y]))
		return false;
	if($y - 1 >= 0 && !$aMap[$y - 1][$x][1] && $aMap[$y - 1][$x][0] == $char)
		$res[] = Array($x, $y - 1, $aMap[$y - 1][$x]);
	if($y + 1 < count($aMap) && !$aMap[$y + 1][$x][1] && $aMap[$y + 1][$x][0] == $char)
		$res[] = Array($x, $y + 1, $aMap[$y + 1][$x]);
	if($x - 1 >= 0 && !$aMap[$y][$x - 1][1] && $aMap[$y][$x - 1][0] == $char)
		$res[] = Array($x - 1, $y, $aMap[$y][$x - 1]);
	if($x + 1 < count($aMap[$y]) && !$aMap[$y][$x + 1][1] && $aMap[$y][$x + 1][0] == $char)
		$res[] = Array($x + 1, $y, $aMap[$y][$x + 1]);
	return $res;
}

function setUsed($x, $y, $aMap){
	if($y < 0 || $y >= count($aMap) || $x < 0 || $x >= count($aMap[$y]))
		return false;
	$aMap[$y][$x][1] = true;
	return $aMap;
}

function findOccurences($char, $aMap){
	$res = Array();
	for($y = 0; $y < count($aMap); $y++){
		for($x = 0; $x < count($aMap[$y]); $x++){
			if($aMap[$y][$x][0] == $char && !$aMap[$y][$x][1])
				$res[] = Array($x, $y, $aMap[$y][$x]);
		}
	}
	return $res;
}

function parseWord($sWord, $aMap, $aLast){
	//echo " -> " . $sWord . "\n";
	if($sWord == "")
		return true;
	$aMap = setUsed($aLast[0], $aLast[1], $aMap);
	$aNeighbors = getNeighbors($aLast[0], $aLast[1], $aMap, substr($sWord, 0, 1));
	for($index = 0; $index < count($aNeighbors); $index++){
		if(parseWord(substr($sWord, 1), $aMap, $aNeighbors[$index])){
			return true;
		}
	}
	return false;
}


function startParseWord($sWord){
	global $map;
	$aOccurences = findOccurences(substr($sWord, 0, 1), $map);
	for($index = 0; $index < count($aOccurences); $index++){
		//echo "START: \n";
		//print_r($aOccurences[$index]);
		if(parseWord(substr($sWord, 1), $map, $aOccurences[$index])){
			//echo "-> true\n";
			return true;
		}
		//echo "-> " . $index . " / " . count($aOccurences) ."\n";
	}
	return false;
}



$fh = fopen($argv[1], "r");
while (true) {
	$line = fgets($fh);
	if($line == "")
		break;
	if(startParseWord(trim($line)))
		echo "True\n";
	else
		echo "False\n";
	//echo "-----------------------------------------\n";
}

?>
