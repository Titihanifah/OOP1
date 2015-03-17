make :
	g++ -o a CommandHistory.cpp ExpressionConverter.cpp ExpressionEvaluator.cpp LogicNumber.cpp OperandConverter.cpp RomanNumber.cpp mCalculator.cpp 
run :
	a
