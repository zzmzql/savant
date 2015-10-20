
#ifndef VHDL_HH
#define VHDL_HH

// Copyright (c) The University of Cincinnati.  All rights reserved.

// UC MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
// OR NON-INFRINGEMENT.  UC SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY
// LICENSEE AS A RESULT OF USING, RESULT OF USING, MODIFYING OR
// DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.

// By using or copying this Software, Licensee agrees to abide by the
// intellectual property laws, and all other applicable laws of the U.S.,
// and the terms of this license.

// You may modify, distribute, and use the software contained in this
// package under the terms of the "GNU LIBRARY GENERAL PUBLIC LICENSE"
// version 2, June 1991. A copy of this license agreement can be found in
// the file "LGPL", distributed with this archive.

#include "savant_config.hh"
#include <fstream>

using std::ofstream;

extern ofstream info_out;    //file used for writing information messages

// include boolean definitions (used if the c++ compiler doesn't have
// the builtin bool data type
#include "savant.hh"

// include template definitions for doubly-linked lists and hash
// tables to be used in various class definitions.
#include "dl_list.hh"

// global flag for parse errors
extern bool parse_error;

// bring in enumerations from aire definition
#include "IRBasicDataTypes.hh"
#include "IRKind.hh"

// bring in concrete class definitions from aire definition
#include "IIRScram_AboveAttribute.hh"
#include "IIRScram_AbsoluteOperator.hh"
#include "IIRScram_AccessSubtypeDefinition.hh"
#include "IIRScram_AccessTypeDefinition.hh"
#include "IIRScram_AcrossAttribute.hh"
#include "IIRScram_ActiveAttribute.hh"
#include "IIRScram_AdditionOperator.hh"
#include "IIRScram_Aggregate.hh"
#include "IIRScram_AliasDeclaration.hh"
#include "IIRScram_Allocator.hh"
#include "IIRScram_AndOperator.hh"
#include "IIRScram_ArchitectureDeclaration.hh"
#include "IIRScram_ArchitectureStatementList.hh"
#include "IIRScram_ArrayNatureDefinition.hh"
#include "IIRScram_ArraySubnatureDefinition.hh"
#include "IIRScram_ArraySubtypeDefinition.hh"
#include "IIRScram_ArrayTypeDefinition.hh"
#include "IIRScram_AscendingAttribute.hh"
#include "IIRScram_AscendingAttribute.hh"
#include "IIRScram_AssertionStatement.hh"
#include "IIRScram_AssociationElementByExpression.hh"
#include "IIRScram_AssociationElementOpen.hh"
#include "IIRScram_AssociationList.hh"
#include "IIRScram_AttributeDeclaration.hh"
#include "IIRScram_AttributeSpecification.hh"
#include "IIRScram_BaseAttribute.hh"
#include "IIRScram_BitStringLiteral.hh"
#include "IIRScram_BlockConfiguration.hh"
#include "IIRScram_BlockStatement.hh"
#include "IIRScram_BranchQuantityDeclaration.hh"
#include "IIRScram_BreakElement.hh"
#include "IIRScram_BreakList.hh"
#include "IIRScram_BreakStatement.hh"
#include "IIRScram_CaseStatement.hh"
#include "IIRScram_CaseStatementAlternativeByChoices.hh"
#include "IIRScram_CaseStatementAlternativeByExpression.hh"
#include "IIRScram_CaseStatementAlternativeByOthers.hh"
#include "IIRScram_CaseStatementAlternativeList.hh"
#include "IIRScram_CharacterLiteral.hh"
#include "IIRScram_Choice.hh"
#include "IIRScram_ChoiceList.hh"
#include "IIRScram_Comment.hh"
#include "IIRScram_CommentList.hh"
#include "IIRScram_ComponentConfiguration.hh"
#include "IIRScram_ComponentDeclaration.hh"
#include "IIRScram_ComponentInstantiationStatement.hh"
#include "IIRScram_ConcatenationOperator.hh"
#include "IIRScram_ConcurrentAssertionStatement.hh"
#include "IIRScram_ConcurrentBreakStatement.hh"
#include "IIRScram_ConcurrentConditionalSignalAssignment.hh"
#include "IIRScram_ConcurrentGenerateForStatement.hh"
#include "IIRScram_ConcurrentGenerateIfStatement.hh"
#include "IIRScram_ConcurrentProcedureCallStatement.hh"
#include "IIRScram_ConcurrentSelectedSignalAssignment.hh"
#include "IIRScram_ConditionalWaveform.hh"
#include "IIRScram_ConditionalWaveformList.hh"
#include "IIRScram_ConfigurationDeclaration.hh"
#include "IIRScram_ConfigurationItemList.hh"
#include "IIRScram_ConfigurationSpecification.hh"
#include "IIRScram_ConstantDeclaration.hh"
#include "IIRScram_ConstantInterfaceDeclaration.hh"
#include "IIRScram_ContributionAttribute.hh"
#include "IIRScram_DeclarationList.hh"
#include "IIRScram_DelayedAttribute.hh"
#include "IIRScram_DesignFile.hh"
#include "IIRScram_DesignFileList.hh"
#include "IIRScram_DesignatorByAll.hh"
#include "IIRScram_DesignatorByOthers.hh"
#include "IIRScram_DesignatorExplicit.hh"
#include "IIRScram_DesignatorList.hh"
#include "IIRScram_DisconnectSpecification.hh"
#include "IIRScram_DivisionOperator.hh"
#include "IIRScram_DotAttribute.hh"
#include "IIRScram_DrivingAttribute.hh"
#include "IIRScram_DrivingValueAttribute.hh"
#include "IIRScram_ElementDeclaration.hh"
#include "IIRScram_ElementDeclarationList.hh"
#include "IIRScram_Elsif.hh"
#include "IIRScram_EntityClassEntry.hh"
#include "IIRScram_EntityClassEntryList.hh"
#include "IIRScram_EntityDeclaration.hh"
#include "IIRScram_EntityNameList.hh"
#include "IIRScram_EnumerationLiteral.hh"
#include "IIRScram_EnumerationLiteralList.hh"
#include "IIRScram_EnumerationSubtypeDefinition.hh"
#include "IIRScram_EnumerationTypeDefinition.hh"
#include "IIRScram_EqualityOperator.hh"
#include "IIRScram_EventAttribute.hh"
#include "IIRScram_ExitStatement.hh"
#include "IIRScram_ExponentiationOperator.hh"
#include "IIRScram_FileDeclaration.hh"
#include "IIRScram_FileInterfaceDeclaration.hh"
#include "IIRScram_FileTypeDefinition.hh"
#include "IIRScram_FloatingPointLiteral.hh"
#include "IIRScram_FloatingPointLiteral32.hh"
#include "IIRScram_FloatingPointLiteral64.hh"
#include "IIRScram_FloatingSubtypeDefinition.hh"
#include "IIRScram_FloatingTypeDefinition.hh"
#include "IIRScram_ForLoopStatement.hh"
#include "IIRScram_FreeQuantityDeclaration.hh"
#include "IIRScram_FunctionCall.hh"
#include "IIRScram_FunctionDeclaration.hh"
#include "IIRScram_GenericList.hh"
#include "IIRScram_GreaterThanOperator.hh"
#include "IIRScram_GreaterThanOrEqualOperator.hh"
#include "IIRScram_GroupConstituent.hh"
#include "IIRScram_GroupDeclaration.hh"
#include "IIRScram_GroupTemplateDeclaration.hh"
#include "IIRScram_HighAttribute.hh"
#include "IIRScram_Identifier.hh"
#include "IIRScram_IdentifierList.hh"
#include "IIRScram_IdentityOperator.hh"
#include "IIRScram_IfStatement.hh"
#include "IIRScram_ImageAttribute.hh"
#include "IIRScram_IndexedName.hh"
#include "IIRScram_InequalityOperator.hh"
#include "IIRScram_InstanceNameAttribute.hh"
#include "IIRScram_IntegerLiteral.hh"
#include "IIRScram_IntegerLiteral32.hh"
#include "IIRScram_IntegerLiteral64.hh"
#include "IIRScram_IntegerSubtypeDefinition.hh"
#include "IIRScram_IntegerTypeDefinition.hh"
#include "IIRScram_InterfaceList.hh"
#include "IIRScram_Label.hh"
#include "IIRScram_LastActiveAttribute.hh"
#include "IIRScram_LastEventAttribute.hh"
#include "IIRScram_LastValueAttribute.hh"
#include "IIRScram_LeftAttribute.hh"
#include "IIRScram_LeftOfAttribute.hh"
#include "IIRScram_LengthAttribute.hh"
#include "IIRScram_LessThanOperator.hh"
#include "IIRScram_LessThanOrEqualOperator.hh"
#include "IIRScram_LibraryClause.hh"
#include "IIRScram_LibraryDeclaration.hh"
#include "IIRScram_LibraryUnit.hh"
#include "IIRScram_LibraryUnitList.hh"
#include "IIRScram_LowAttribute.hh"
#include "IIRScram_LTFAttribute.hh"
#include "IIRScram_ModulusOperator.hh"
#include "IIRScram_MultiplicationOperator.hh"
#include "IIRScram_NameList.hh"
#include "IIRScram_NandOperator.hh"
#include "IIRScram_NatureDeclaration.hh"
#include "IIRScram_NatureDefinition.hh"
#include "IIRScram_NegationOperator.hh"
#include "IIRScram_NextStatement.hh"
#include "IIRScram_NorOperator.hh"
#include "IIRScram_NotOperator.hh"
#include "IIRScram_NullStatement.hh"
#include "IIRScram_OrOperator.hh"
#include "IIRScram_OthersInitialization.hh"
#include "IIRScram_PackageBodyDeclaration.hh"
#include "IIRScram_PackageDeclaration.hh"
#include "IIRScram_PathNameAttribute.hh"
#include "IIRScram_PhysicalLiteral.hh"
#include "IIRScram_PhysicalSubtypeDefinition.hh"
#include "IIRScram_PhysicalTypeDefinition.hh"
#include "IIRScram_PhysicalUnit.hh"
#include "IIRScram_PortList.hh"
#include "IIRScram_PosAttribute.hh"
#include "IIRScram_PredAttribute.hh"
#include "IIRScram_ProcedureCallStatement.hh"
#include "IIRScram_ProcedureDeclaration.hh"
#include "IIRScram_ProcessStatement.hh"
#include "IIRScram_QualifiedExpression.hh"
#include "IIRScram_QuantityDeclaration.hh"
#include "IIRScram_QuietAttribute.hh"
#include "IIRScram_ROLOperator.hh"
#include "IIRScram_ROROperator.hh"
#include "IIRScram_RangeAttribute.hh"
#include "IIRScram_RangeTypeDefinition.hh"
#include "IIRScram_RecordTypeDefinition.hh"
#include "IIRScram_ReferenceAttribute.hh"
#include "IIRScram_RemainderOperator.hh"
#include "IIRScram_ReportStatement.hh"
#include "IIRScram_ReturnStatement.hh"
#include "IIRScram_ReverseRangeAttribute.hh"
#include "IIRScram_RightAttribute.hh"
#include "IIRScram_RightOfAttribute.hh"
#include "IIRScram_SLAOperator.hh"
#include "IIRScram_SLLOperator.hh"
#include "IIRScram_SRAOperator.hh"
#include "IIRScram_SRLOperator.hh"
#include "IIRScram_ScalarNatureDefinition.hh"
#include "IIRScram_SelectedName.hh"
#include "IIRScram_SelectedNameByAll.hh"
#include "IIRScram_SelectedWaveform.hh"
#include "IIRScram_SelectedWaveformList.hh"
#include "IIRScram_SensitizedProcessStatement.hh"
#include "IIRScram_SequentialStatementList.hh"
#include "IIRScram_SharedVariableDeclaration.hh"
#include "IIRScram_SignalAssignmentStatement.hh"
#include "IIRScram_SignalDeclaration.hh"
#include "IIRScram_SignalInterfaceDeclaration.hh"
#include "IIRScram_Signature.hh"
#include "IIRScram_SimpleName.hh"
#include "IIRScram_SimpleNameAttribute.hh"
#include "IIRScram_SimpleSimultaneousStatement.hh"
#include "IIRScram_SimultaneousElsif.hh"
#include "IIRScram_SimultaneousIfStatement.hh"
#include "IIRScram_SimultaneousStatement.hh"
#include "IIRScram_SliceName.hh"
#include "IIRScram_SourceQuantityDeclaration.hh"
#include "IIRScram_StableAttribute.hh"
#include "IIRScram_StringLiteral.hh"
#include "IIRScram_SubtractionOperator.hh"
#include "IIRScram_SubtypeDeclaration.hh"
#include "IIRScram_SuccAttribute.hh"
#include "IIRScram_TerminalDeclaration.hh"
#include "IIRScram_TerminalInterfaceDeclaration.hh"
#include "IIRScram_ThroughAttribute.hh"
#include "IIRScram_TransactionAttribute.hh"
#include "IIRScram_TypeConversion.hh"
#include "IIRScram_TypeDeclaration.hh"
#include "IIRScram_UnitList.hh"
#include "IIRScram_UseClause.hh"
#include "IIRScram_UserAttribute.hh"
#include "IIRScram_ValAttribute.hh"
#include "IIRScram_ValueAttribute.hh"
#include "IIRScram_VariableAssignmentStatement.hh"
#include "IIRScram_VariableDeclaration.hh"
#include "IIRScram_VariableInterfaceDeclaration.hh"
#include "IIRScram_WaitStatement.hh"
#include "IIRScram_WaveformElement.hh"
#include "IIRScram_WaveformList.hh"
#include "IIRScram_WhileLoopStatement.hh"
#include "IIRScram_XnorOperator.hh"
#include "IIRScram_XorOperator.hh"
#include "IIRScram_ZTFAttribute.hh" 
#include "IIRBase_IncompleteTypeDefinition.hh"

#endif