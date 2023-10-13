'''
@file CPPModule.py
@author David R
@date 06 Dec 2022 16:42

This is a short little script that will generate a C/CPP Module based on the
module name passed as an arg from invocation.

'''

# Common Imports  -------------------------------------------------------------
import sys
import os
from datetime import date

# Custom Imports  -------------------------------------------------------------

# Global Vars  ----------------------------------------------------------------

PROGRAM_NAME = "GenModule.py"
ARG_OPT_CPP = "-cpp"
ARG_OPT_C = "-c"

ARG_IDX_PROGNAME = 0
ARG_IDX_MODULENAME = 1
ARG_IDX_MODULETYPE = 2

OPT_CPP_STR = "C++"
OPT_C_STR = "C"

dictModTypeStrings = \
{
	ARG_OPT_CPP : OPT_CPP_STR,
	ARG_OPT_C 	: OPT_C_STR	
}

# C/C++ output file related variables

# Module Class  ---------------------------------------------------------------

class CodeModule:
	def __init__(self, name, type):
		self.name = name
		self.type = type
		self.srcFileName = ""
		self.hdrFileName = f'{name}.h'
  
		if ( self.type != None ):
			if ( self.type == OPT_CPP_STR ):
				self.srcFileName = f'{self.name}.cpp'
			elif ( self.type == OPT_C_STR ):
				self.srcFileName = f'{self.name}.c'
		self.today = date.today().strftime("%d %b %Y")

	def getName(self):
		return self.name

	def getSrcFileName(self):
		return self.srcFileName

	def getHdrFileName(self):
		return self.hdrFileName
	
	def addSections(self, outfile):
		tempStr = "-" * 60
		outfile.writelines(f'// Core includes    {tempStr}\n\n')
		outfile.writelines(f'// Module includes  {tempStr}\n\n')
		outfile.writelines(f'// Defines/Macros   {tempStr}\n\n')
		outfile.writelines(f'// Enumerations     {tempStr}\n\n')
		outfile.writelines(f'// Structures       {tempStr}\n\n')
		outfile.writelines(f'// Local Functions  {tempStr}\n\n')
		outfile.writelines(f'// Local Variables  {tempStr}\n\n')
		outfile.writelines(f'// Const variables  {tempStr}\n\n')
		outfile.writelines(f'// Global variables {tempStr}\n\n')

	def genHeader(self, outfile):
		# 80-char wide column
		strStartBlock = "/" + ("*" * 79) + "\n"
		srtEndBlock = ("*" * 79) + "/\n\n"

		# First is the starting block
		outfile.writelines(strStartBlock)
		outfile.writelines(f'  @file {self.hdrFileName}\n')
		outfile.writelines(f'  @date {self.today}\n')
		outfile.writelines(f'  @author David R\n')
		outfile.writelines(f'  @brief \n')
		outfile.writelines("\n")
		outfile.writelines(f'  @version 1.0\n')
		outfile.writelines("\n")
		outfile.writelines(f'  \\addtogroup {module.getName()} \n')
		outfile.writelines("  @{\n")
		outfile.writelines(srtEndBlock)

		# Next is the header guard
		outfile.writelines(f'#ifndef _{module.getName().upper()}_H \n')
		outfile.writelines(f'#define _{module.getName().upper()}_H \n')
		outfile.writelines("\n")

		self.addSections(outfile)
		tempStr = "-" * 60
		outfile.writelines(f'// Func Prototypes  {tempStr}\n\n')

		outfile.writelines(f'#ifdef __cplusplus\n')
		outfile.writelines(f'extern "C" {{\n')
		outfile.writelines(f'#endif // __cplusplus\n\n\n\n')

		outfile.writelines(f'#ifdef __cplusplus\n')
		outfile.writelines(f'}};\n')
		outfile.writelines(f'#endif // __cplusplus\n')

		outfile.writelines("\n")
		outfile.writelines(f'#endif  //  _{module.getName().upper()}_H \n\n')

		# Common to both Source and Header files	
		tempStr = "}"
		outfile.writelines(f'/** @{tempStr} {self.hdrFileName} */\n')

	def genSourceFile(self, outfile):
		# 80-char wide column
		strStartBlock = "/" + ("*" * 79) + "\n"
		srtEndBlock = ("*" * 79) + "/\n\n"

		# First is the starting block
		outfile.writelines(strStartBlock)
		outfile.writelines(f'  @file {self.srcFileName}\n')
		outfile.writelines(f'  @date  {self.today}\n')
		outfile.writelines(f'  @author David R\n')
		outfile.writelines(f'  @brief \n')
		outfile.writelines("\n")
		outfile.writelines(f'  @version 1.0\n')
		outfile.writelines("\n")
		outfile.writelines(f'  \\addtogroup {module.getName()} \n')
		outfile.writelines("  @{\n")
		outfile.writelines(srtEndBlock)

		self.addSections(outfile)
		tempStr = "-" * 60
		outfile.writelines(f'// Func Definitions {tempStr}\n\n')

		# One function documentation thing
		outfile.writelines(strStartBlock)
		outfile.writelines(f' * @function \n')
		outfile.writelines(f' *\n')
		outfile.writelines(f' * @brief \n')
		outfile.writelines(f' *\n')
		outfile.writelines(f' * @param[io] \n')
		outfile.writelines(f' * @param[in] \n')
		outfile.writelines(f' * @param[out] \n')
		outfile.writelines(f' *\n')
		outfile.writelines(f' * @return  \n')
		outfile.writelines(srtEndBlock)

		# Section div for private functions
		tempStr = "/" * 80
		outfile.writelines(f'{tempStr}\n')
		outfile.writelines(f'//  Static Functions \n')
		outfile.writelines(f'{tempStr}\n\n\n\n')

		# Common to both Source and Header files	
		tempStr = "}"
		outfile.writelines(f'/** @{tempStr} {self.srcFileName} */\n')

# Helper functions  -----------------------------------------------------------

def printUsage():
	print(f'Usage: \npython3 {PROGRAM_NAME} <module_name> {ARG_OPT_CPP}/{ARG_OPT_C}')
 
 
# Main  -----------------------------------------------------------------------

numArgs = len(sys.argv)
if (numArgs < 2):
	printUsage()
	exit()

moduleName = sys.argv[ARG_IDX_MODULENAME]
moduleType = dictModTypeStrings[sys.argv[ARG_IDX_MODULETYPE]]
print(f'You want to create a {moduleType} module called {moduleName}')

module = CodeModule(moduleName, moduleType)

try: 
	moduleDir = os.mkdir(moduleName)
except OSError as error:
	print(error)

srcFile = open(f'{moduleName}/{module.getSrcFileName()}', "w")
module.genSourceFile(srcFile)
srcFile.close()

hdrFile = open(f'{moduleName}/{module.getHdrFileName()}', "w")
module.genHeader(hdrFile)
hdrFile.close()

