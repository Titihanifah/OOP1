all: Calculator.cpp CommandHistory.cc ExpressionConverter.cpp ExpressionEvaluator.cc ArabicNumber.cpp LogicNumber.cpp OperandConverter.cc RomanNumber.cpp mCalculator.cpp
	g++ -o a ExpressionConverter.cpp ExpressionEvaluator.cc LogicNumber.cpp ArabicNumber.cpp OperandConverter.cc RomanNumber.cpp Calculator.cpp CommandHistory.cc mCalculator.cpp 

