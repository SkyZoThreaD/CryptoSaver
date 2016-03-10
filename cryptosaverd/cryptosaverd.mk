##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cryptosaverd
ConfigurationName      :=Debug
WorkspacePath          := "/home/tupac/Documents/CryptoSaver"
ProjectPath            := "/home/tupac/Documents/CryptoSaver/cryptosaverd"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=03/10/16
CodeLitePath           :="/home/tupac/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="cryptosaverd.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)pthread 
ArLibs                 :=  "pthread" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++14 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -std=c++14 -std=c++11 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/VFS_connector.cpp$(ObjectSuffix) $(IntermediateDirectory)/logger.cpp$(ObjectSuffix) $(IntermediateDirectory)/exception.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/CryptoSaver/cryptosaverd/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/VFS_connector.cpp$(ObjectSuffix): VFS_connector.cpp $(IntermediateDirectory)/VFS_connector.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/CryptoSaver/cryptosaverd/VFS_connector.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/VFS_connector.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/VFS_connector.cpp$(DependSuffix): VFS_connector.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/VFS_connector.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/VFS_connector.cpp$(DependSuffix) -MM "VFS_connector.cpp"

$(IntermediateDirectory)/VFS_connector.cpp$(PreprocessSuffix): VFS_connector.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/VFS_connector.cpp$(PreprocessSuffix) "VFS_connector.cpp"

$(IntermediateDirectory)/logger.cpp$(ObjectSuffix): logger.cpp $(IntermediateDirectory)/logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/CryptoSaver/cryptosaverd/logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/logger.cpp$(DependSuffix): logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/logger.cpp$(DependSuffix) -MM "logger.cpp"

$(IntermediateDirectory)/logger.cpp$(PreprocessSuffix): logger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/logger.cpp$(PreprocessSuffix) "logger.cpp"

$(IntermediateDirectory)/exception.cpp$(ObjectSuffix): exception.cpp $(IntermediateDirectory)/exception.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/tupac/Documents/CryptoSaver/cryptosaverd/exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/exception.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/exception.cpp$(DependSuffix): exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/exception.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/exception.cpp$(DependSuffix) -MM "exception.cpp"

$(IntermediateDirectory)/exception.cpp$(PreprocessSuffix): exception.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/exception.cpp$(PreprocessSuffix) "exception.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


