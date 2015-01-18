//Sample code to read in test cases:
var fs  = require("fs");

function compareStrings(sString, sPattern){
	var lPatternIndex = 0;
	var bActive = false;
	var bEscape = false;
	for(var index = 0; index < sString.length; index++){
		if(sString[index] == sPattern[lPatternIndex]){
			bActive = true;
			if(lPatternIndex + 1 < sPattern.length){
				lPatternIndex++;
			}else{
				console.log("true");
				return;
			}
		}else if(sPattern[lPatternIndex] == "*" && !bEscape){
			bActive = false;
			bEscape = false;
			if(lPatternIndex + 1 < sPattern.length){
				lPatternIndex++;
				index--;
			}
		}else if(sPattern[lPatternIndex] == "\\"){
			bEscape = true;
			if(lPatternIndex + 1 < sPattern.length){
				lPatternIndex++;
				index--;
			}
		}else if(bActive){
			console.log("false");
			return;
		}
	}
	if(sPattern != "")
		console.log("false");
	else
		console.log("true");
}

fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
	if (line !== "") {
		var aSplit = line.split(",");
		if(aSplit.length == 2){
			if(aSplit[1][0] == "*"){
				console.log("false");
				return;
			}
			compareStrings(aSplit[0], aSplit[1]);
		}
	}else{
		console.log("true");
		return 0;
	}
});
