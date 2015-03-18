/* Calculator.h */
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "CommandHistory.h"
#include "OperandConverter.h"
#include "ExpressionConverter.h"
#include "ExpressionEvaluator.h"
#include "Stack.h"
#include <sstream>
using namespace std;
//! Class Calculator.
/*! 
	Class Calculator merupakan class yang mengatur eksekusi dari setiap masukan user
*/
class Calculator {
	private :
		//! varibael tipe operator
		int OprType;
		//! varibael tipe nomor
		int NumType;
		//! varibael tipe ekspresi
		int ExpType;
		//! varibael tipe mode
		int Mode;
		//! objek yang dibentuk dari CommandHistory
		CommandHistory cmdHistory;
		//! objek yang dibentuk dari OperandConverter
		OperandConverter oprConverter;
		//! objek yang dibentuk dari ExpressionConverter
		ExpressionConverter expConverter;
		//! objek yang dibentuk dari ExpressionEvaluator
		ExpressionEvaluator expEvaluator;
		//! objek yang dibentuk dari RomanNumber
		RomanNumber rom;
		//! fungsi isExpression digunakan untuk melakukan pengecekkan apakah masukan dari pengguna berupa ekspresi atau bukan.
		/*! 
			jika fungsi mengembalikan nilai 1, maka masukan merupakan ekspresi, sebaliknya jika mfungsi mengembalikan 0, maka masukan bukan ekspresi
		*/
		int isExpression(string in);
	public :
		//! Calculator constructor.
		/*!
			memasukan default pada jenis operator, jenis nomor, dan jenis ekspresi
		*/
		Calculator();
		//! Calculator copy constructor.
		Calculator(const Calculator&);
		//! Calculator destructor.
		~Calculator();
		//! konstanta untuk jenis ekspresi.
		const static int POSTFIKS_OPERATOR = 2;
		const static int INFIKS_OPERATOR = 1;
		const static int PREFIKS_OPERATOR = 3;
		//! konstanta untuk jenis operator.
		const static int ARITMATIKA_OPERATOR = 1;
		const static int LOGIKA_OPERATOR = 2;
		//! konstanta untuk jenis angka.
		const static int ARABIC_NUMBER = 1;
		const static int ROMAWI_NUMBER = 2;
		const static int LOGIC_NUMBER = 3;
		//! konstanta untuk jenis mode.
		const static int MODE_HITUNG = 1;
		const static int MODE_SETTING = 2;
		//! prosedur setOperatorType.
		/*!
			I.S. Operator di-set dengan default (operator aritmatika) pada constructor
			F.S. Operator di-set sesuai masukan dari user
		*/
		void setOperatorType(int);
		//! prosedur setNumberType.
		/*!
			I.S. Nomor di-set dengan default (angka arab) pada constructor
			F.S. Nomor di-set sesuai masukan dari user
		*/
		void setNumberType(int);
		//! prosedur setExpressionType.
		/*!
			I.S. Ekspresi di-set dengan default (infiks) pada constructor
			F.S. Ekspresi di-set sesuai masukan dari user
		*/
		void setExpressionType(int);
		//! fungsi untuk mengambil jenis operator yang dipilih.
		int getOperatorType();
		//! fungsi untuk mengambil jenis nomor yang dipilih.
		int getNumberType();
		//! fungsi untuk mengambil jenis ekspresi yang dipilih.
		int getExpressionType();
		//! prosedur setMode
		/*!
			I.S. Mode di-set dengan default (ekspresi)
			F.S. Ekspresi di-set sesuai perintah dari user, 1 merupakan mode ekspresi dan 2 merupakan mode settings
		*/
		void setMode(int);
		//! fungsi untuk mengambil mode yang dipilih pennguna.
		int getMode();
		//! prosedur executeCommand
		/*!
			prosedur executeCommand digunakan untuk menjalankan semua perintah yang dimasukan oleh pengguna
		*/
		void executeCommand(string);
};
#endif