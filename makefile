make :
	g++ -o test CommandHistory.cpp ExpressionConverter.cpp ExpressionEvaluator.cpp LogicNumber.cpp OperandConverter.cpp RomanNumber.cpp mCalculator.cpp 
run :
	test
