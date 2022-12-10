'''
@file CPPModule.py
@author David R
@date 06 Dec 2022 16:42

This is a short little script that will generate a CPP Module based on the
module name passed as an arg from invocation.

'''

# Common Imports  -------------------------------------------------------------
import sys
import os

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

	def getName(self):
		return self.name

	def getSrcFileName(self):
		return self.srcFileName

	def getHdrFileName(self):
		return self.hdrFileName

# Helper functions  -----------------------------------------------------------

def printUsage():
	print(f'Usage: \npython3 {PROGRAM_NAME} <module_name> {ARG_OPT_CPP}/{ARG_OPT_C}')
 
def printFileStart(outFile, module, bIsHeader=False):
	# 80-char wide column
	strStartBlock = "/" + ("*" * 79) + "\n"
	srtEndBlock = ("*" * 79) + "/\n\n"
	filename = ""
	if (bIsHeader == True):
		filename = module.getHdrFileName()
	else:
		filename = module.getSrcFileName()

	# First is the starting block
	outFile.writelines(strStartBlock)
	outFile.writelines(f'  @file {filename}\n')
	outFile.writelines(f'  @date \n')
	outFile.writelines(f'  @author \n')
	outFile.writelines(f'  @brief \n')
	outFile.writelines("\n")
	outFile.writelines(f'  @version 1.0\n')
	outFile.writelines("\n")
	outFile.writelines(f'  \\addtogroup {module.getName()} \n')
	outFile.writelines("  @{\n")
	outFile.writelines(srtEndBlock)

	if (bIsHeader == True):
		# Next is the header guard
		outFile.writelines(f'#ifndef _{module.getName().upper()}_H \n')
		outFile.writelines(f'#define _{module.getName().upper()}_H \n')
		outFile.writelines("\n")

	# Common stuff for bouth source and header files
	tempStr = "-" * 60
	outFile.writelines(f'// Core includes    {tempStr}\n\n')
	outFile.writelines(f'// Module includes  {tempStr}\n\n')
	outFile.writelines(f'// Defines/Macros   {tempStr}\n\n')
	outFile.writelines(f'// Enumerations     {tempStr}\n\n')
	outFile.writelines(f'// Structures       {tempStr}\n\n')
	outFile.writelines(f'// Local Variables  {tempStr}\n\n')
	outFile.writelines(f'// Func Prototypes  {tempStr}\n\n')
	outFile.writelines(f'// Const variables  {tempStr}\n\n')
	outFile.writelines(f'// Global variables {tempStr}\n\n')
  
	if (bIsHeader == True):
		outFile.writelines("\n")
		outFile.writelines(f'#endif  //  _{module.getName().upper()}_H \n\n')

	# Common to both Source and Header files	
	tempStr = "}"
	outFile.writelines(f'/** @{tempStr} {filename} */\n')
  
 
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
printFileStart(srcFile, module)
srcFile.close()

hdrFile = open(f'{moduleName}/{module.getHdrFileName()}', "w")
printFileStart(hdrFile, module, bIsHeader=True)
hdrFile.close()



print("Check it out!")