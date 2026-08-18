
// Generated from CSubset.g4 by ANTLR 4.13.2


#include "CSubsetVisitor.h"

#include "CSubsetParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CSubsetParserStaticData final {
  CSubsetParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSubsetParserStaticData(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData(CSubsetParserStaticData&&) = delete;
  CSubsetParserStaticData& operator=(const CSubsetParserStaticData&) = delete;
  CSubsetParserStaticData& operator=(CSubsetParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag csubsetParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CSubsetParserStaticData> csubsetParserStaticData = nullptr;

void csubsetParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csubsetParserStaticData != nullptr) {
    return;
  }
#else
  assert(csubsetParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSubsetParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "type_specifier", 
      "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "'++'", "'--'", "'!'", "", "", 
      "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
      "ID", "CONST_INT", "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,32,313,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,55,8,1,10,1,12,1,58,
  	9,1,1,2,1,2,1,2,3,2,63,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,3,3,78,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,3,4,93,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,103,8,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,5,5,113,8,5,10,5,12,5,116,9,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,3,6,124,8,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,3,8,133,8,8,1,9,1,9,1,9,
  	1,9,1,9,1,9,3,9,141,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,5,9,155,8,9,10,9,12,9,158,9,9,1,10,1,10,1,10,1,10,1,10,5,10,165,8,10,
  	10,10,12,10,168,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,188,8,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,205,
  	8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,218,
  	8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,226,8,13,1,14,1,14,1,14,1,14,
  	1,14,3,14,233,8,14,1,15,1,15,1,15,1,15,1,15,3,15,240,8,15,1,16,1,16,1,
  	16,1,16,1,16,3,16,247,8,16,1,17,1,17,1,17,1,17,1,17,1,17,5,17,255,8,17,
  	10,17,12,17,258,9,17,1,18,1,18,1,18,1,18,1,18,1,18,5,18,266,8,18,10,18,
  	12,18,269,9,18,1,19,1,19,1,19,1,19,1,19,3,19,276,8,19,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,3,20,296,8,20,1,21,1,21,3,21,300,8,21,1,22,1,22,1,22,1,22,1,22,1,
  	22,5,22,308,8,22,10,22,12,22,311,9,22,1,22,0,7,2,10,18,20,34,36,44,23,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,0,0,333,
  	0,46,1,0,0,0,2,49,1,0,0,0,4,62,1,0,0,0,6,77,1,0,0,0,8,92,1,0,0,0,10,102,
  	1,0,0,0,12,123,1,0,0,0,14,125,1,0,0,0,16,132,1,0,0,0,18,140,1,0,0,0,20,
  	159,1,0,0,0,22,204,1,0,0,0,24,217,1,0,0,0,26,225,1,0,0,0,28,232,1,0,0,
  	0,30,239,1,0,0,0,32,246,1,0,0,0,34,248,1,0,0,0,36,259,1,0,0,0,38,275,
  	1,0,0,0,40,295,1,0,0,0,42,299,1,0,0,0,44,301,1,0,0,0,46,47,3,2,1,0,47,
  	48,5,0,0,1,48,1,1,0,0,0,49,50,6,1,-1,0,50,51,3,4,2,0,51,56,1,0,0,0,52,
  	53,10,2,0,0,53,55,3,4,2,0,54,52,1,0,0,0,55,58,1,0,0,0,56,54,1,0,0,0,56,
  	57,1,0,0,0,57,3,1,0,0,0,58,56,1,0,0,0,59,63,3,14,7,0,60,63,3,6,3,0,61,
  	63,3,8,4,0,62,59,1,0,0,0,62,60,1,0,0,0,62,61,1,0,0,0,63,5,1,0,0,0,64,
  	65,3,16,8,0,65,66,5,30,0,0,66,67,5,14,0,0,67,68,3,10,5,0,68,69,5,15,0,
  	0,69,70,5,20,0,0,70,78,1,0,0,0,71,72,3,16,8,0,72,73,5,30,0,0,73,74,5,
  	14,0,0,74,75,5,15,0,0,75,76,5,20,0,0,76,78,1,0,0,0,77,64,1,0,0,0,77,71,
  	1,0,0,0,78,7,1,0,0,0,79,80,3,16,8,0,80,81,5,30,0,0,81,82,5,14,0,0,82,
  	83,3,10,5,0,83,84,5,15,0,0,84,85,3,12,6,0,85,93,1,0,0,0,86,87,3,16,8,
  	0,87,88,5,30,0,0,88,89,5,14,0,0,89,90,5,15,0,0,90,91,3,12,6,0,91,93,1,
  	0,0,0,92,79,1,0,0,0,92,86,1,0,0,0,93,9,1,0,0,0,94,95,6,5,-1,0,95,96,3,
  	16,8,0,96,97,5,30,0,0,97,103,1,0,0,0,98,99,3,16,8,0,99,100,5,22,0,0,100,
  	103,1,0,0,0,101,103,3,16,8,0,102,94,1,0,0,0,102,98,1,0,0,0,102,101,1,
  	0,0,0,103,114,1,0,0,0,104,105,10,5,0,0,105,106,5,21,0,0,106,107,3,16,
  	8,0,107,108,5,30,0,0,108,113,1,0,0,0,109,110,10,4,0,0,110,111,5,21,0,
  	0,111,113,3,16,8,0,112,104,1,0,0,0,112,109,1,0,0,0,113,116,1,0,0,0,114,
  	112,1,0,0,0,114,115,1,0,0,0,115,11,1,0,0,0,116,114,1,0,0,0,117,118,5,
  	16,0,0,118,119,3,20,10,0,119,120,5,17,0,0,120,124,1,0,0,0,121,122,5,16,
  	0,0,122,124,5,17,0,0,123,117,1,0,0,0,123,121,1,0,0,0,124,13,1,0,0,0,125,
  	126,3,16,8,0,126,127,3,18,9,0,127,128,5,20,0,0,128,15,1,0,0,0,129,133,
  	5,11,0,0,130,133,5,12,0,0,131,133,5,13,0,0,132,129,1,0,0,0,132,130,1,
  	0,0,0,132,131,1,0,0,0,133,17,1,0,0,0,134,135,6,9,-1,0,135,141,5,30,0,
  	0,136,137,5,30,0,0,137,138,5,18,0,0,138,139,5,31,0,0,139,141,5,19,0,0,
  	140,134,1,0,0,0,140,136,1,0,0,0,141,156,1,0,0,0,142,143,10,5,0,0,143,
  	144,5,21,0,0,144,155,5,30,0,0,145,146,10,4,0,0,146,147,5,21,0,0,147,148,
  	5,30,0,0,148,149,5,18,0,0,149,150,5,31,0,0,150,155,5,19,0,0,151,152,10,
  	3,0,0,152,153,5,22,0,0,153,155,5,30,0,0,154,142,1,0,0,0,154,145,1,0,0,
  	0,154,151,1,0,0,0,155,158,1,0,0,0,156,154,1,0,0,0,156,157,1,0,0,0,157,
  	19,1,0,0,0,158,156,1,0,0,0,159,160,6,10,-1,0,160,161,3,22,11,0,161,166,
  	1,0,0,0,162,163,10,1,0,0,163,165,3,22,11,0,164,162,1,0,0,0,165,168,1,
  	0,0,0,166,164,1,0,0,0,166,167,1,0,0,0,167,21,1,0,0,0,168,166,1,0,0,0,
  	169,205,3,14,7,0,170,205,3,24,12,0,171,205,3,12,6,0,172,173,5,7,0,0,173,
  	174,5,14,0,0,174,175,3,24,12,0,175,176,3,24,12,0,176,177,3,28,14,0,177,
  	178,5,15,0,0,178,179,3,22,11,0,179,205,1,0,0,0,180,181,5,5,0,0,181,182,
  	5,14,0,0,182,183,3,28,14,0,183,184,5,15,0,0,184,187,3,22,11,0,185,186,
  	5,6,0,0,186,188,3,22,11,0,187,185,1,0,0,0,187,188,1,0,0,0,188,205,1,0,
  	0,0,189,190,5,8,0,0,190,191,5,14,0,0,191,192,3,28,14,0,192,193,5,15,0,
  	0,193,194,3,22,11,0,194,205,1,0,0,0,195,196,5,9,0,0,196,197,5,14,0,0,
  	197,198,5,30,0,0,198,199,5,15,0,0,199,205,5,20,0,0,200,201,5,10,0,0,201,
  	202,3,28,14,0,202,203,5,20,0,0,203,205,1,0,0,0,204,169,1,0,0,0,204,170,
  	1,0,0,0,204,171,1,0,0,0,204,172,1,0,0,0,204,180,1,0,0,0,204,189,1,0,0,
  	0,204,195,1,0,0,0,204,200,1,0,0,0,205,23,1,0,0,0,206,218,5,20,0,0,207,
  	208,3,28,14,0,208,209,5,20,0,0,209,218,1,0,0,0,210,211,3,26,13,0,211,
  	212,5,29,0,0,212,213,3,34,17,0,213,214,5,22,0,0,214,215,5,29,0,0,215,
  	218,1,0,0,0,216,218,3,28,14,0,217,206,1,0,0,0,217,207,1,0,0,0,217,210,
  	1,0,0,0,217,216,1,0,0,0,218,25,1,0,0,0,219,226,5,30,0,0,220,221,5,30,
  	0,0,221,222,5,18,0,0,222,223,3,28,14,0,223,224,5,19,0,0,224,226,1,0,0,
  	0,225,219,1,0,0,0,225,220,1,0,0,0,226,27,1,0,0,0,227,233,3,30,15,0,228,
  	229,3,26,13,0,229,230,5,29,0,0,230,231,3,30,15,0,231,233,1,0,0,0,232,
  	227,1,0,0,0,232,228,1,0,0,0,233,29,1,0,0,0,234,240,3,32,16,0,235,236,
  	3,32,16,0,236,237,5,28,0,0,237,238,3,32,16,0,238,240,1,0,0,0,239,234,
  	1,0,0,0,239,235,1,0,0,0,240,31,1,0,0,0,241,247,3,34,17,0,242,243,3,34,
  	17,0,243,244,5,27,0,0,244,245,3,34,17,0,245,247,1,0,0,0,246,241,1,0,0,
  	0,246,242,1,0,0,0,247,33,1,0,0,0,248,249,6,17,-1,0,249,250,3,36,18,0,
  	250,256,1,0,0,0,251,252,10,1,0,0,252,253,5,22,0,0,253,255,3,36,18,0,254,
  	251,1,0,0,0,255,258,1,0,0,0,256,254,1,0,0,0,256,257,1,0,0,0,257,35,1,
  	0,0,0,258,256,1,0,0,0,259,260,6,18,-1,0,260,261,3,38,19,0,261,267,1,0,
  	0,0,262,263,10,1,0,0,263,264,5,23,0,0,264,266,3,38,19,0,265,262,1,0,0,
  	0,266,269,1,0,0,0,267,265,1,0,0,0,267,268,1,0,0,0,268,37,1,0,0,0,269,
  	267,1,0,0,0,270,271,5,22,0,0,271,276,3,38,19,0,272,273,5,26,0,0,273,276,
  	3,38,19,0,274,276,3,40,20,0,275,270,1,0,0,0,275,272,1,0,0,0,275,274,1,
  	0,0,0,276,39,1,0,0,0,277,296,3,26,13,0,278,279,5,30,0,0,279,280,5,14,
  	0,0,280,281,3,42,21,0,281,282,5,15,0,0,282,296,1,0,0,0,283,284,5,14,0,
  	0,284,285,3,28,14,0,285,286,5,15,0,0,286,296,1,0,0,0,287,296,5,31,0,0,
  	288,296,5,32,0,0,289,290,3,26,13,0,290,291,5,24,0,0,291,296,1,0,0,0,292,
  	293,3,26,13,0,293,294,5,25,0,0,294,296,1,0,0,0,295,277,1,0,0,0,295,278,
  	1,0,0,0,295,283,1,0,0,0,295,287,1,0,0,0,295,288,1,0,0,0,295,289,1,0,0,
  	0,295,292,1,0,0,0,296,41,1,0,0,0,297,300,3,44,22,0,298,300,1,0,0,0,299,
  	297,1,0,0,0,299,298,1,0,0,0,300,43,1,0,0,0,301,302,6,22,-1,0,302,303,
  	3,30,15,0,303,309,1,0,0,0,304,305,10,2,0,0,305,306,5,21,0,0,306,308,3,
  	30,15,0,307,304,1,0,0,0,308,311,1,0,0,0,309,307,1,0,0,0,309,310,1,0,0,
  	0,310,45,1,0,0,0,311,309,1,0,0,0,26,56,62,77,92,102,112,114,123,132,140,
  	154,156,166,187,204,217,225,232,239,246,256,267,275,295,299,309
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csubsetParserStaticData = std::move(staticData);
}

}

CSubsetParser::CSubsetParser(TokenStream *input) : CSubsetParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CSubsetParser::CSubsetParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CSubsetParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *csubsetParserStaticData->atn, csubsetParserStaticData->decisionToDFA, csubsetParserStaticData->sharedContextCache, options);
}

CSubsetParser::~CSubsetParser() {
  delete _interpreter;
}

const atn::ATN& CSubsetParser::getATN() const {
  return *csubsetParserStaticData->atn;
}

std::string CSubsetParser::getGrammarFileName() const {
  return "CSubset.g4";
}

const std::vector<std::string>& CSubsetParser::getRuleNames() const {
  return csubsetParserStaticData->ruleNames;
}

const dfa::Vocabulary& CSubsetParser::getVocabulary() const {
  return csubsetParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSubsetParser::getSerializedATN() const {
  return csubsetParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

CSubsetParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StartContext::getRuleIndex() const {
  return CSubsetParser::RuleStart;
}

void CSubsetParser::StartContext::copyFrom(StartContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StartProgramContext ------------------------------------------------------------------

CSubsetParser::ProgramContext* CSubsetParser::StartProgramContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}

tree::TerminalNode* CSubsetParser::StartProgramContext::EOF() {
  return getToken(CSubsetParser::EOF, 0);
}

CSubsetParser::StartProgramContext::StartProgramContext(StartContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StartProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStartProgram(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::StartContext* CSubsetParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CSubsetParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<CSubsetParser::StartProgramContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(46);
    program(0);
    setState(47);
    match(CSubsetParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

CSubsetParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ProgramContext::getRuleIndex() const {
  return CSubsetParser::RuleProgram;
}

void CSubsetParser::ProgramContext::copyFrom(ProgramContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProgramSingleUnitContext ------------------------------------------------------------------

CSubsetParser::UnitContext* CSubsetParser::ProgramSingleUnitContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::ProgramSingleUnitContext::ProgramSingleUnitContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ProgramSingleUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgramSingleUnit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProgramMultipleUnitsContext ------------------------------------------------------------------

CSubsetParser::ProgramContext* CSubsetParser::ProgramMultipleUnitsContext::program() {
  return getRuleContext<CSubsetParser::ProgramContext>(0);
}

CSubsetParser::UnitContext* CSubsetParser::ProgramMultipleUnitsContext::unit() {
  return getRuleContext<CSubsetParser::UnitContext>(0);
}

CSubsetParser::ProgramMultipleUnitsContext::ProgramMultipleUnitsContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ProgramMultipleUnitsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitProgramMultipleUnits(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::ProgramContext* CSubsetParser::program() {
   return program(0);
}

CSubsetParser::ProgramContext* CSubsetParser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  CSubsetParser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, CSubsetParser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<ProgramSingleUnitContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(50);
    unit();
    _ctx->stop = _input->LT(-1);
    setState(56);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ProgramMultipleUnitsContext>(_tracker.createInstance<ProgramContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleProgram);
        setState(52);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(53);
        unit(); 
      }
      setState(58);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

CSubsetParser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::UnitContext::getRuleIndex() const {
  return CSubsetParser::RuleUnit;
}

void CSubsetParser::UnitContext::copyFrom(UnitContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnitFunctionDefinitionContext ------------------------------------------------------------------

CSubsetParser::Func_definitionContext* CSubsetParser::UnitFunctionDefinitionContext::func_definition() {
  return getRuleContext<CSubsetParser::Func_definitionContext>(0);
}

CSubsetParser::UnitFunctionDefinitionContext::UnitFunctionDefinitionContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnitFunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnitFunctionDeclarationContext ------------------------------------------------------------------

CSubsetParser::Func_declarationContext* CSubsetParser::UnitFunctionDeclarationContext::func_declaration() {
  return getRuleContext<CSubsetParser::Func_declarationContext>(0);
}

CSubsetParser::UnitFunctionDeclarationContext::UnitFunctionDeclarationContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnitFunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnitVariableDeclarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext* CSubsetParser::UnitVariableDeclarationContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::UnitVariableDeclarationContext::UnitVariableDeclarationContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnitVariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::UnitContext* CSubsetParser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, CSubsetParser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::UnitVariableDeclarationContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(59);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::UnitFunctionDeclarationContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(60);
      func_declaration();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::UnitFunctionDefinitionContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(61);
      func_definition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

CSubsetParser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Func_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_declaration;
}

void CSubsetParser::Func_declarationContext::copyFrom(Func_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionDeclarationWithParametersContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FunctionDeclarationWithParametersContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithParametersContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithParametersContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::FunctionDeclarationWithParametersContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithParametersContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithParametersContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::FunctionDeclarationWithParametersContext::FunctionDeclarationWithParametersContext(Func_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FunctionDeclarationWithParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclarationWithParameters(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionDeclarationWithoutParametersContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FunctionDeclarationWithoutParametersContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithoutParametersContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithoutParametersContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithoutParametersContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDeclarationWithoutParametersContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::FunctionDeclarationWithoutParametersContext::FunctionDeclarationWithoutParametersContext(Func_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FunctionDeclarationWithoutParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclarationWithoutParameters(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Func_declarationContext* CSubsetParser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, CSubsetParser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FunctionDeclarationWithParametersContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(64);
      type_specifier();
      setState(65);
      match(CSubsetParser::ID);
      setState(66);
      match(CSubsetParser::LPAREN);
      setState(67);
      parameter_list(0);
      setState(68);
      match(CSubsetParser::RPAREN);
      setState(69);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FunctionDeclarationWithoutParametersContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(71);
      type_specifier();
      setState(72);
      match(CSubsetParser::ID);
      setState(73);
      match(CSubsetParser::LPAREN);
      setState(74);
      match(CSubsetParser::RPAREN);
      setState(75);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

CSubsetParser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Func_definitionContext::getRuleIndex() const {
  return CSubsetParser::RuleFunc_definition;
}

void CSubsetParser::Func_definitionContext::copyFrom(Func_definitionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionDefinitionWithParametersContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FunctionDefinitionWithParametersContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithParametersContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithParametersContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::FunctionDefinitionWithParametersContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithParametersContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Compound_statementContext* CSubsetParser::FunctionDefinitionWithParametersContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::FunctionDefinitionWithParametersContext::FunctionDefinitionWithParametersContext(Func_definitionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FunctionDefinitionWithParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinitionWithParameters(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionDefinitionWithoutParametersContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::FunctionDefinitionWithoutParametersContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithoutParametersContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithoutParametersContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::FunctionDefinitionWithoutParametersContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::Compound_statementContext* CSubsetParser::FunctionDefinitionWithoutParametersContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::FunctionDefinitionWithoutParametersContext::FunctionDefinitionWithoutParametersContext(Func_definitionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FunctionDefinitionWithoutParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinitionWithoutParameters(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Func_definitionContext* CSubsetParser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, CSubsetParser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::FunctionDefinitionWithParametersContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(79);
      type_specifier();
      setState(80);
      match(CSubsetParser::ID);
      setState(81);
      match(CSubsetParser::LPAREN);
      setState(82);
      parameter_list(0);
      setState(83);
      match(CSubsetParser::RPAREN);
      setState(84);
      compound_statement();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FunctionDefinitionWithoutParametersContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(86);
      type_specifier();
      setState(87);
      match(CSubsetParser::ID);
      setState(88);
      match(CSubsetParser::LPAREN);
      setState(89);
      match(CSubsetParser::RPAREN);
      setState(90);
      compound_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Parameter_listContext::getRuleIndex() const {
  return CSubsetParser::RuleParameter_list;
}

void CSubsetParser::Parameter_listContext::copyFrom(Parameter_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParameterSingleNamedContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterSingleNamedContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::ParameterSingleNamedContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::ParameterSingleNamedContext::ParameterSingleNamedContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterSingleNamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterSingleNamed(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterSingleInvalidNameContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterSingleInvalidNameContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::ParameterSingleInvalidNameContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::ParameterSingleInvalidNameContext::ParameterSingleInvalidNameContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterSingleInvalidNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterSingleInvalidName(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterAppendNamedContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext* CSubsetParser::ParameterAppendNamedContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::ParameterAppendNamedContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterAppendNamedContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubsetParser::ParameterAppendNamedContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::ParameterAppendNamedContext::ParameterAppendNamedContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterAppendNamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterAppendNamed(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterAppendUnnamedContext ------------------------------------------------------------------

CSubsetParser::Parameter_listContext* CSubsetParser::ParameterAppendUnnamedContext::parameter_list() {
  return getRuleContext<CSubsetParser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubsetParser::ParameterAppendUnnamedContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterAppendUnnamedContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::ParameterAppendUnnamedContext::ParameterAppendUnnamedContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterAppendUnnamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterAppendUnnamed(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterSingleUnnamedContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::ParameterSingleUnnamedContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::ParameterSingleUnnamedContext::ParameterSingleUnnamedContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParameterSingleUnnamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParameterSingleUnnamed(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list() {
   return parameter_list(0);
}

CSubsetParser::Parameter_listContext* CSubsetParser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  CSubsetParser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, CSubsetParser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(102);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParameterSingleNamedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(95);
      type_specifier();
      setState(96);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParameterSingleInvalidNameContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(98);
      type_specifier();
      setState(99);
      match(CSubsetParser::ADDOP);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ParameterSingleUnnamedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(101);
      type_specifier();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(114);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(112);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ParameterAppendNamedContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(104);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(105);
          match(CSubsetParser::COMMA);
          setState(106);
          type_specifier();
          setState(107);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ParameterAppendUnnamedContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(109);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(110);
          match(CSubsetParser::COMMA);
          setState(111);
          type_specifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(116);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

CSubsetParser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Compound_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleCompound_statement;
}

void CSubsetParser::Compound_statementContext::copyFrom(Compound_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CompoundWithStatementsContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::CompoundWithStatementsContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

CSubsetParser::StatementsContext* CSubsetParser::CompoundWithStatementsContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

tree::TerminalNode* CSubsetParser::CompoundWithStatementsContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::CompoundWithStatementsContext::CompoundWithStatementsContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::CompoundWithStatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitCompoundWithStatements(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptyCompoundContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::EmptyCompoundContext::LCURL() {
  return getToken(CSubsetParser::LCURL, 0);
}

tree::TerminalNode* CSubsetParser::EmptyCompoundContext::RCURL() {
  return getToken(CSubsetParser::RCURL, 0);
}

CSubsetParser::EmptyCompoundContext::EmptyCompoundContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::EmptyCompoundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitEmptyCompound(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Compound_statementContext* CSubsetParser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, CSubsetParser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::CompoundWithStatementsContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(117);
      match(CSubsetParser::LCURL);
      setState(118);
      statements(0);
      setState(119);
      match(CSubsetParser::RCURL);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::EmptyCompoundContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(121);
      match(CSubsetParser::LCURL);
      setState(122);
      match(CSubsetParser::RCURL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Var_declarationContext::getRuleIndex() const {
  return CSubsetParser::RuleVar_declaration;
}

void CSubsetParser::Var_declarationContext::copyFrom(Var_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext* CSubsetParser::VariableDeclarationContext::type_specifier() {
  return getRuleContext<CSubsetParser::Type_specifierContext>(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::VariableDeclarationContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::VariableDeclarationContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::VariableDeclarationContext::VariableDeclarationContext(Var_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Var_declarationContext* CSubsetParser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, CSubsetParser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<CSubsetParser::VariableDeclarationContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(125);
    type_specifier();
    setState(126);
    declaration_list(0);
    setState(127);
    match(CSubsetParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

CSubsetParser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Type_specifierContext::getRuleIndex() const {
  return CSubsetParser::RuleType_specifier;
}

void CSubsetParser::Type_specifierContext::copyFrom(Type_specifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IntegerTypeContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::IntegerTypeContext::INT() {
  return getToken(CSubsetParser::INT, 0);
}

CSubsetParser::IntegerTypeContext::IntegerTypeContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::IntegerTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitIntegerType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VoidTypeContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::VoidTypeContext::VOID() {
  return getToken(CSubsetParser::VOID, 0);
}

CSubsetParser::VoidTypeContext::VoidTypeContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::VoidTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVoidType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatTypeContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FloatTypeContext::FLOAT() {
  return getToken(CSubsetParser::FLOAT, 0);
}

CSubsetParser::FloatTypeContext::FloatTypeContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FloatTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFloatType(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Type_specifierContext* CSubsetParser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 16, CSubsetParser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::INT: {
        _localctx = _tracker.createInstance<CSubsetParser::IntegerTypeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(129);
        match(CSubsetParser::INT);
        break;
      }

      case CSubsetParser::FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::FloatTypeContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(130);
        match(CSubsetParser::FLOAT);
        break;
      }

      case CSubsetParser::VOID: {
        _localctx = _tracker.createInstance<CSubsetParser::VoidTypeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(131);
        match(CSubsetParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Declaration_listContext::getRuleIndex() const {
  return CSubsetParser::RuleDeclaration_list;
}

void CSubsetParser::Declaration_listContext::copyFrom(Declaration_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeclarationAppendArrayContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext* CSubsetParser::DeclarationAppendArrayContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::DeclarationAppendArrayContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationAppendArrayContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationAppendArrayContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationAppendArrayContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationAppendArrayContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::DeclarationAppendArrayContext::DeclarationAppendArrayContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationAppendArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationAppendArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationInvalidSeparatorContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext* CSubsetParser::DeclarationInvalidSeparatorContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::DeclarationInvalidSeparatorContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationInvalidSeparatorContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::DeclarationInvalidSeparatorContext::DeclarationInvalidSeparatorContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationInvalidSeparatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationInvalidSeparator(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationAppendScalarContext ------------------------------------------------------------------

CSubsetParser::Declaration_listContext* CSubsetParser::DeclarationAppendScalarContext::declaration_list() {
  return getRuleContext<CSubsetParser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubsetParser::DeclarationAppendScalarContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationAppendScalarContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::DeclarationAppendScalarContext::DeclarationAppendScalarContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationAppendScalarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationAppendScalar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationSingleScalarContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclarationSingleScalarContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::DeclarationSingleScalarContext::DeclarationSingleScalarContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationSingleScalarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationSingleScalar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationSingleArrayContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::DeclarationSingleArrayContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationSingleArrayContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationSingleArrayContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

tree::TerminalNode* CSubsetParser::DeclarationSingleArrayContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::DeclarationSingleArrayContext::DeclarationSingleArrayContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::DeclarationSingleArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitDeclarationSingleArray(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list() {
   return declaration_list(0);
}

CSubsetParser::Declaration_listContext* CSubsetParser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  CSubsetParser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, CSubsetParser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(140);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<DeclarationSingleScalarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(135);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<DeclarationSingleArrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(136);
      match(CSubsetParser::ID);
      setState(137);
      match(CSubsetParser::LTHIRD);
      setState(138);
      match(CSubsetParser::CONST_INT);
      setState(139);
      match(CSubsetParser::RTHIRD);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(156);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(154);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<DeclarationAppendScalarContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(142);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(143);
          match(CSubsetParser::COMMA);
          setState(144);
          match(CSubsetParser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DeclarationAppendArrayContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(145);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(146);
          match(CSubsetParser::COMMA);
          setState(147);
          match(CSubsetParser::ID);
          setState(148);
          match(CSubsetParser::LTHIRD);
          setState(149);
          match(CSubsetParser::CONST_INT);
          setState(150);
          match(CSubsetParser::RTHIRD);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<DeclarationInvalidSeparatorContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(151);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(152);
          match(CSubsetParser::ADDOP);
          setState(153);
          match(CSubsetParser::ID);
          break;
        }

        default:
          break;
        } 
      }
      setState(158);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

CSubsetParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StatementsContext::getRuleIndex() const {
  return CSubsetParser::RuleStatements;
}

void CSubsetParser::StatementsContext::copyFrom(StatementsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatementsSingleContext ------------------------------------------------------------------

CSubsetParser::StatementContext* CSubsetParser::StatementsSingleContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementsSingleContext::StatementsSingleContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementsSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementsSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementsAppendContext ------------------------------------------------------------------

CSubsetParser::StatementsContext* CSubsetParser::StatementsAppendContext::statements() {
  return getRuleContext<CSubsetParser::StatementsContext>(0);
}

CSubsetParser::StatementContext* CSubsetParser::StatementsAppendContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::StatementsAppendContext::StatementsAppendContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementsAppendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementsAppend(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::StatementsContext* CSubsetParser::statements() {
   return statements(0);
}

CSubsetParser::StatementsContext* CSubsetParser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  CSubsetParser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CSubsetParser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<StatementsSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(160);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(166);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<StatementsAppendContext>(_tracker.createInstance<StatementsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleStatements);
        setState(162);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(163);
        statement(); 
      }
      setState(168);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CSubsetParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::StatementContext::getRuleIndex() const {
  return CSubsetParser::RuleStatement;
}

void CSubsetParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatementVariableDeclarationContext ------------------------------------------------------------------

CSubsetParser::Var_declarationContext* CSubsetParser::StatementVariableDeclarationContext::var_declaration() {
  return getRuleContext<CSubsetParser::Var_declarationContext>(0);
}

CSubsetParser::StatementVariableDeclarationContext::StatementVariableDeclarationContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementVariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStatementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::IfStatementContext::IF() {
  return getToken(CSubsetParser::IF, 0);
}

tree::TerminalNode* CSubsetParser::IfStatementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::IfStatementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::IfStatementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

std::vector<CSubsetParser::StatementContext *> CSubsetParser::IfStatementContext::statement() {
  return getRuleContexts<CSubsetParser::StatementContext>();
}

CSubsetParser::StatementContext* CSubsetParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<CSubsetParser::StatementContext>(i);
}

tree::TerminalNode* CSubsetParser::IfStatementContext::ELSE() {
  return getToken(CSubsetParser::ELSE, 0);
}

CSubsetParser::IfStatementContext::IfStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintlnStatementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::PrintlnStatementContext::PRINTLN() {
  return getToken(CSubsetParser::PRINTLN, 0);
}

tree::TerminalNode* CSubsetParser::PrintlnStatementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

tree::TerminalNode* CSubsetParser::PrintlnStatementContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::PrintlnStatementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

tree::TerminalNode* CSubsetParser::PrintlnStatementContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::PrintlnStatementContext::PrintlnStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::PrintlnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitPrintlnStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementExpressionContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext* CSubsetParser::StatementExpressionContext::expression_statement() {
  return getRuleContext<CSubsetParser::Expression_statementContext>(0);
}

CSubsetParser::StatementExpressionContext::StatementExpressionContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementCompoundContext ------------------------------------------------------------------

CSubsetParser::Compound_statementContext* CSubsetParser::StatementCompoundContext::compound_statement() {
  return getRuleContext<CSubsetParser::Compound_statementContext>(0);
}

CSubsetParser::StatementCompoundContext::StatementCompoundContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::StatementCompoundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitStatementCompound(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStatementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ReturnStatementContext::RETURN() {
  return getToken(CSubsetParser::RETURN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::ReturnStatementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::ReturnStatementContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::ReturnStatementContext::ReturnStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStatementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::WhileStatementContext::WHILE() {
  return getToken(CSubsetParser::WHILE, 0);
}

tree::TerminalNode* CSubsetParser::WhileStatementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::WhileStatementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::WhileStatementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::StatementContext* CSubsetParser::WhileStatementContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::WhileStatementContext::WhileStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForStatementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ForStatementContext::FOR() {
  return getToken(CSubsetParser::FOR, 0);
}

tree::TerminalNode* CSubsetParser::ForStatementContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

std::vector<CSubsetParser::Expression_statementContext *> CSubsetParser::ForStatementContext::expression_statement() {
  return getRuleContexts<CSubsetParser::Expression_statementContext>();
}

CSubsetParser::Expression_statementContext* CSubsetParser::ForStatementContext::expression_statement(size_t i) {
  return getRuleContext<CSubsetParser::Expression_statementContext>(i);
}

CSubsetParser::ExpressionContext* CSubsetParser::ForStatementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::ForStatementContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::StatementContext* CSubsetParser::ForStatementContext::statement() {
  return getRuleContext<CSubsetParser::StatementContext>(0);
}

CSubsetParser::ForStatementContext::ForStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::StatementContext* CSubsetParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, CSubsetParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(204);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::INT:
      case CSubsetParser::FLOAT:
      case CSubsetParser::VOID: {
        _localctx = _tracker.createInstance<CSubsetParser::StatementVariableDeclarationContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(169);
        var_declaration();
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::SEMICOLON:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::StatementExpressionContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(170);
        expression_statement();
        break;
      }

      case CSubsetParser::LCURL: {
        _localctx = _tracker.createInstance<CSubsetParser::StatementCompoundContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(171);
        compound_statement();
        break;
      }

      case CSubsetParser::FOR: {
        _localctx = _tracker.createInstance<CSubsetParser::ForStatementContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(172);
        match(CSubsetParser::FOR);
        setState(173);
        match(CSubsetParser::LPAREN);
        setState(174);
        expression_statement();
        setState(175);
        expression_statement();
        setState(176);
        expression();
        setState(177);
        match(CSubsetParser::RPAREN);
        setState(178);
        statement();
        break;
      }

      case CSubsetParser::IF: {
        _localctx = _tracker.createInstance<CSubsetParser::IfStatementContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(180);
        match(CSubsetParser::IF);
        setState(181);
        match(CSubsetParser::LPAREN);
        setState(182);
        expression();
        setState(183);
        match(CSubsetParser::RPAREN);
        setState(184);
        statement();
        setState(187);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          setState(185);
          match(CSubsetParser::ELSE);
          setState(186);
          statement();
          break;
        }

        default:
          break;
        }
        break;
      }

      case CSubsetParser::WHILE: {
        _localctx = _tracker.createInstance<CSubsetParser::WhileStatementContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(189);
        match(CSubsetParser::WHILE);
        setState(190);
        match(CSubsetParser::LPAREN);
        setState(191);
        expression();
        setState(192);
        match(CSubsetParser::RPAREN);
        setState(193);
        statement();
        break;
      }

      case CSubsetParser::PRINTLN: {
        _localctx = _tracker.createInstance<CSubsetParser::PrintlnStatementContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(195);
        match(CSubsetParser::PRINTLN);
        setState(196);
        match(CSubsetParser::LPAREN);
        setState(197);
        match(CSubsetParser::ID);
        setState(198);
        match(CSubsetParser::RPAREN);
        setState(199);
        match(CSubsetParser::SEMICOLON);
        break;
      }

      case CSubsetParser::RETURN: {
        _localctx = _tracker.createInstance<CSubsetParser::ReturnStatementContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(200);
        match(CSubsetParser::RETURN);
        setState(201);
        expression();
        setState(202);
        match(CSubsetParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

CSubsetParser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Expression_statementContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression_statement;
}

void CSubsetParser::Expression_statementContext::copyFrom(Expression_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MissingSemicolonExpressionStatementContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext* CSubsetParser::MissingSemicolonExpressionStatementContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

CSubsetParser::MissingSemicolonExpressionStatementContext::MissingSemicolonExpressionStatementContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::MissingSemicolonExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitMissingSemicolonExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptyExpressionStatementContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::EmptyExpressionStatementContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::EmptyExpressionStatementContext::EmptyExpressionStatementContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::EmptyExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitEmptyExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpressionStatementWithExpressionContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext* CSubsetParser::ExpressionStatementWithExpressionContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::ExpressionStatementWithExpressionContext::SEMICOLON() {
  return getToken(CSubsetParser::SEMICOLON, 0);
}

CSubsetParser::ExpressionStatementWithExpressionContext::ExpressionStatementWithExpressionContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ExpressionStatementWithExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitExpressionStatementWithExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InvalidOperandExpressionStatementContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::InvalidOperandExpressionStatementContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

std::vector<tree::TerminalNode *> CSubsetParser::InvalidOperandExpressionStatementContext::ASSIGNOP() {
  return getTokens(CSubsetParser::ASSIGNOP);
}

tree::TerminalNode* CSubsetParser::InvalidOperandExpressionStatementContext::ASSIGNOP(size_t i) {
  return getToken(CSubsetParser::ASSIGNOP, i);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::InvalidOperandExpressionStatementContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

tree::TerminalNode* CSubsetParser::InvalidOperandExpressionStatementContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::InvalidOperandExpressionStatementContext::InvalidOperandExpressionStatementContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::InvalidOperandExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitInvalidOperandExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Expression_statementContext* CSubsetParser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, CSubsetParser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(217);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::EmptyExpressionStatementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(206);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::ExpressionStatementWithExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(207);
      expression();
      setState(208);
      match(CSubsetParser::SEMICOLON);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::InvalidOperandExpressionStatementContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(210);
      variable();
      setState(211);
      match(CSubsetParser::ASSIGNOP);
      setState(212);
      simple_expression(0);
      setState(213);
      match(CSubsetParser::ADDOP);
      setState(214);
      match(CSubsetParser::ASSIGNOP);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::MissingSemicolonExpressionStatementContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(216);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

CSubsetParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::VariableContext::getRuleIndex() const {
  return CSubsetParser::RuleVariable;
}

void CSubsetParser::VariableContext::copyFrom(VariableContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ScalarVariableContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ScalarVariableContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

CSubsetParser::ScalarVariableContext::ScalarVariableContext(VariableContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ScalarVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitScalarVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayVariableContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ArrayVariableContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::ArrayVariableContext::LTHIRD() {
  return getToken(CSubsetParser::LTHIRD, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::ArrayVariableContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::ArrayVariableContext::RTHIRD() {
  return getToken(CSubsetParser::RTHIRD, 0);
}

CSubsetParser::ArrayVariableContext::ArrayVariableContext(VariableContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArrayVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArrayVariable(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::VariableContext* CSubsetParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 26, CSubsetParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::ScalarVariableContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(219);
      match(CSubsetParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::ArrayVariableContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(220);
      match(CSubsetParser::ID);
      setState(221);
      match(CSubsetParser::LTHIRD);
      setState(222);
      expression();
      setState(223);
      match(CSubsetParser::RTHIRD);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CSubsetParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ExpressionContext::getRuleIndex() const {
  return CSubsetParser::RuleExpression;
}

void CSubsetParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LogicOnlyExpressionContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext* CSubsetParser::LogicOnlyExpressionContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::LogicOnlyExpressionContext::LogicOnlyExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::LogicOnlyExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitLogicOnlyExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentExpressionContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::AssignmentExpressionContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::AssignmentExpressionContext::ASSIGNOP() {
  return getToken(CSubsetParser::ASSIGNOP, 0);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::AssignmentExpressionContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::AssignmentExpressionContext::AssignmentExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::ExpressionContext* CSubsetParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, CSubsetParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::LogicOnlyExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(227);
      logic_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::AssignmentExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(228);
      variable();
      setState(229);
      match(CSubsetParser::ASSIGNOP);
      setState(230);
      logic_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Logic_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleLogic_expression;
}

void CSubsetParser::Logic_expressionContext::copyFrom(Logic_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryLogicExpressionContext ------------------------------------------------------------------

std::vector<CSubsetParser::Rel_expressionContext *> CSubsetParser::BinaryLogicExpressionContext::rel_expression() {
  return getRuleContexts<CSubsetParser::Rel_expressionContext>();
}

CSubsetParser::Rel_expressionContext* CSubsetParser::BinaryLogicExpressionContext::rel_expression(size_t i) {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(i);
}

tree::TerminalNode* CSubsetParser::BinaryLogicExpressionContext::LOGICOP() {
  return getToken(CSubsetParser::LOGICOP, 0);
}

CSubsetParser::BinaryLogicExpressionContext::BinaryLogicExpressionContext(Logic_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::BinaryLogicExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitBinaryLogicExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelOnlyLogicExpressionContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext* CSubsetParser::RelOnlyLogicExpressionContext::rel_expression() {
  return getRuleContext<CSubsetParser::Rel_expressionContext>(0);
}

CSubsetParser::RelOnlyLogicExpressionContext::RelOnlyLogicExpressionContext(Logic_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::RelOnlyLogicExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitRelOnlyLogicExpression(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Logic_expressionContext* CSubsetParser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 30, CSubsetParser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::RelOnlyLogicExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(234);
      rel_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::BinaryLogicExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(235);
      rel_expression();
      setState(236);
      match(CSubsetParser::LOGICOP);
      setState(237);
      rel_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

CSubsetParser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Rel_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleRel_expression;
}

void CSubsetParser::Rel_expressionContext::copyFrom(Rel_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimpleOnlyRelExpressionContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext* CSubsetParser::SimpleOnlyRelExpressionContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

CSubsetParser::SimpleOnlyRelExpressionContext::SimpleOnlyRelExpressionContext(Rel_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::SimpleOnlyRelExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSimpleOnlyRelExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryRelExpressionContext ------------------------------------------------------------------

std::vector<CSubsetParser::Simple_expressionContext *> CSubsetParser::BinaryRelExpressionContext::simple_expression() {
  return getRuleContexts<CSubsetParser::Simple_expressionContext>();
}

CSubsetParser::Simple_expressionContext* CSubsetParser::BinaryRelExpressionContext::simple_expression(size_t i) {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(i);
}

tree::TerminalNode* CSubsetParser::BinaryRelExpressionContext::RELOP() {
  return getToken(CSubsetParser::RELOP, 0);
}

CSubsetParser::BinaryRelExpressionContext::BinaryRelExpressionContext(Rel_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::BinaryRelExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitBinaryRelExpression(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Rel_expressionContext* CSubsetParser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, CSubsetParser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(246);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::SimpleOnlyRelExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(241);
      simple_expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::BinaryRelExpressionContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(242);
      simple_expression(0);
      setState(243);
      match(CSubsetParser::RELOP);
      setState(244);
      simple_expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Simple_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleSimple_expression;
}

void CSubsetParser::Simple_expressionContext::copyFrom(Simple_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TermOnlySimpleExpressionContext ------------------------------------------------------------------

CSubsetParser::TermContext* CSubsetParser::TermOnlySimpleExpressionContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::TermOnlySimpleExpressionContext::TermOnlySimpleExpressionContext(Simple_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::TermOnlySimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitTermOnlySimpleExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveExpressionContext ------------------------------------------------------------------

CSubsetParser::Simple_expressionContext* CSubsetParser::AdditiveExpressionContext::simple_expression() {
  return getRuleContext<CSubsetParser::Simple_expressionContext>(0);
}

tree::TerminalNode* CSubsetParser::AdditiveExpressionContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::TermContext* CSubsetParser::AdditiveExpressionContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

CSubsetParser::AdditiveExpressionContext::AdditiveExpressionContext(Simple_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression() {
   return simple_expression(0);
}

CSubsetParser::Simple_expressionContext* CSubsetParser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  CSubsetParser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CSubsetParser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<TermOnlySimpleExpressionContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(249);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(256);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AdditiveExpressionContext>(_tracker.createInstance<Simple_expressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleSimple_expression);
        setState(251);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(252);
        match(CSubsetParser::ADDOP);
        setState(253);
        term(0); 
      }
      setState(258);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

CSubsetParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::TermContext::getRuleIndex() const {
  return CSubsetParser::RuleTerm;
}

void CSubsetParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultiplicativeTermContext ------------------------------------------------------------------

CSubsetParser::TermContext* CSubsetParser::MultiplicativeTermContext::term() {
  return getRuleContext<CSubsetParser::TermContext>(0);
}

tree::TerminalNode* CSubsetParser::MultiplicativeTermContext::MULOP() {
  return getToken(CSubsetParser::MULOP, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::MultiplicativeTermContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::MultiplicativeTermContext::MultiplicativeTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::MultiplicativeTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeTerm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryOnlyTermContext ------------------------------------------------------------------

CSubsetParser::Unary_expressionContext* CSubsetParser::UnaryOnlyTermContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::UnaryOnlyTermContext::UnaryOnlyTermContext(TermContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::UnaryOnlyTermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitUnaryOnlyTerm(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::TermContext* CSubsetParser::term() {
   return term(0);
}

CSubsetParser::TermContext* CSubsetParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  CSubsetParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CSubsetParser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<UnaryOnlyTermContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(260);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(267);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MultiplicativeTermContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(262);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(263);
        match(CSubsetParser::MULOP);
        setState(264);
        unary_expression(); 
      }
      setState(269);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

CSubsetParser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Unary_expressionContext::getRuleIndex() const {
  return CSubsetParser::RuleUnary_expression;
}

void CSubsetParser::Unary_expressionContext::copyFrom(Unary_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SignedUnaryContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::SignedUnaryContext::ADDOP() {
  return getToken(CSubsetParser::ADDOP, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::SignedUnaryContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::SignedUnaryContext::SignedUnaryContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::SignedUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitSignedUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactorUnaryContext ------------------------------------------------------------------

CSubsetParser::FactorContext* CSubsetParser::FactorUnaryContext::factor() {
  return getRuleContext<CSubsetParser::FactorContext>(0);
}

CSubsetParser::FactorUnaryContext::FactorUnaryContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FactorUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFactorUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotUnaryContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::NotUnaryContext::NOT() {
  return getToken(CSubsetParser::NOT, 0);
}

CSubsetParser::Unary_expressionContext* CSubsetParser::NotUnaryContext::unary_expression() {
  return getRuleContext<CSubsetParser::Unary_expressionContext>(0);
}

CSubsetParser::NotUnaryContext::NotUnaryContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::NotUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitNotUnary(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Unary_expressionContext* CSubsetParser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 38, CSubsetParser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(275);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::ADDOP: {
        _localctx = _tracker.createInstance<CSubsetParser::SignedUnaryContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(270);
        match(CSubsetParser::ADDOP);
        setState(271);
        unary_expression();
        break;
      }

      case CSubsetParser::NOT: {
        _localctx = _tracker.createInstance<CSubsetParser::NotUnaryContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(272);
        match(CSubsetParser::NOT);
        setState(273);
        unary_expression();
        break;
      }

      case CSubsetParser::LPAREN:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::FactorUnaryContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(274);
        factor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

CSubsetParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::FactorContext::getRuleIndex() const {
  return CSubsetParser::RuleFactor;
}

void CSubsetParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionCallFactorContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FunctionCallFactorContext::ID() {
  return getToken(CSubsetParser::ID, 0);
}

tree::TerminalNode* CSubsetParser::FunctionCallFactorContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::Argument_listContext* CSubsetParser::FunctionCallFactorContext::argument_list() {
  return getRuleContext<CSubsetParser::Argument_listContext>(0);
}

tree::TerminalNode* CSubsetParser::FunctionCallFactorContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::FunctionCallFactorContext::FunctionCallFactorContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FunctionCallFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFunctionCallFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostDecrementFactorContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::PostDecrementFactorContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::PostDecrementFactorContext::DECOP() {
  return getToken(CSubsetParser::DECOP, 0);
}

CSubsetParser::PostDecrementFactorContext::PostDecrementFactorContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::PostDecrementFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitPostDecrementFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntegerConstantFactorContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::IntegerConstantFactorContext::CONST_INT() {
  return getToken(CSubsetParser::CONST_INT, 0);
}

CSubsetParser::IntegerConstantFactorContext::IntegerConstantFactorContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::IntegerConstantFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitIntegerConstantFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatConstantFactorContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::FloatConstantFactorContext::CONST_FLOAT() {
  return getToken(CSubsetParser::CONST_FLOAT, 0);
}

CSubsetParser::FloatConstantFactorContext::FloatConstantFactorContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::FloatConstantFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitFloatConstantFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostIncrementFactorContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::PostIncrementFactorContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

tree::TerminalNode* CSubsetParser::PostIncrementFactorContext::INCOP() {
  return getToken(CSubsetParser::INCOP, 0);
}

CSubsetParser::PostIncrementFactorContext::PostIncrementFactorContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::PostIncrementFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitPostIncrementFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableFactorContext ------------------------------------------------------------------

CSubsetParser::VariableContext* CSubsetParser::VariableFactorContext::variable() {
  return getRuleContext<CSubsetParser::VariableContext>(0);
}

CSubsetParser::VariableFactorContext::VariableFactorContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::VariableFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitVariableFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedFactorContext ------------------------------------------------------------------

tree::TerminalNode* CSubsetParser::ParenthesizedFactorContext::LPAREN() {
  return getToken(CSubsetParser::LPAREN, 0);
}

CSubsetParser::ExpressionContext* CSubsetParser::ParenthesizedFactorContext::expression() {
  return getRuleContext<CSubsetParser::ExpressionContext>(0);
}

tree::TerminalNode* CSubsetParser::ParenthesizedFactorContext::RPAREN() {
  return getToken(CSubsetParser::RPAREN, 0);
}

CSubsetParser::ParenthesizedFactorContext::ParenthesizedFactorContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ParenthesizedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitParenthesizedFactor(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::FactorContext* CSubsetParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 40, CSubsetParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(295);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubsetParser::VariableFactorContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(277);
      variable();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubsetParser::FunctionCallFactorContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(278);
      match(CSubsetParser::ID);
      setState(279);
      match(CSubsetParser::LPAREN);
      setState(280);
      argument_list();
      setState(281);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubsetParser::ParenthesizedFactorContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(283);
      match(CSubsetParser::LPAREN);
      setState(284);
      expression();
      setState(285);
      match(CSubsetParser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubsetParser::IntegerConstantFactorContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(287);
      match(CSubsetParser::CONST_INT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubsetParser::FloatConstantFactorContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(288);
      match(CSubsetParser::CONST_FLOAT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubsetParser::PostIncrementFactorContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(289);
      variable();
      setState(290);
      match(CSubsetParser::INCOP);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubsetParser::PostDecrementFactorContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(292);
      variable();
      setState(293);
      match(CSubsetParser::DECOP);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

CSubsetParser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::Argument_listContext::getRuleIndex() const {
  return CSubsetParser::RuleArgument_list;
}

void CSubsetParser::Argument_listContext::copyFrom(Argument_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NonEmptyArgumentListContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext* CSubsetParser::NonEmptyArgumentListContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

CSubsetParser::NonEmptyArgumentListContext::NonEmptyArgumentListContext(Argument_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::NonEmptyArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitNonEmptyArgumentList(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptyArgumentListContext ------------------------------------------------------------------

CSubsetParser::EmptyArgumentListContext::EmptyArgumentListContext(Argument_listContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::EmptyArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitEmptyArgumentList(this);
  else
    return visitor->visitChildren(this);
}
CSubsetParser::Argument_listContext* CSubsetParser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 42, CSubsetParser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(299);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubsetParser::LPAREN:
      case CSubsetParser::ADDOP:
      case CSubsetParser::NOT:
      case CSubsetParser::ID:
      case CSubsetParser::CONST_INT:
      case CSubsetParser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubsetParser::NonEmptyArgumentListContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(297);
        arguments(0);
        break;
      }

      case CSubsetParser::RPAREN: {
        _localctx = _tracker.createInstance<CSubsetParser::EmptyArgumentListContext>(_localctx);
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubsetParser::ArgumentsContext::getRuleIndex() const {
  return CSubsetParser::RuleArguments;
}

void CSubsetParser::ArgumentsContext::copyFrom(ArgumentsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArgumentSingleContext ------------------------------------------------------------------

CSubsetParser::Logic_expressionContext* CSubsetParser::ArgumentSingleContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ArgumentSingleContext::ArgumentSingleContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgumentSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgumentSingle(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgumentAppendContext ------------------------------------------------------------------

CSubsetParser::ArgumentsContext* CSubsetParser::ArgumentAppendContext::arguments() {
  return getRuleContext<CSubsetParser::ArgumentsContext>(0);
}

tree::TerminalNode* CSubsetParser::ArgumentAppendContext::COMMA() {
  return getToken(CSubsetParser::COMMA, 0);
}

CSubsetParser::Logic_expressionContext* CSubsetParser::ArgumentAppendContext::logic_expression() {
  return getRuleContext<CSubsetParser::Logic_expressionContext>(0);
}

CSubsetParser::ArgumentAppendContext::ArgumentAppendContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubsetParser::ArgumentAppendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubsetVisitor*>(visitor))
    return parserVisitor->visitArgumentAppend(this);
  else
    return visitor->visitChildren(this);
}

CSubsetParser::ArgumentsContext* CSubsetParser::arguments() {
   return arguments(0);
}

CSubsetParser::ArgumentsContext* CSubsetParser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubsetParser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  CSubsetParser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CSubsetParser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<ArgumentSingleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(302);
    logic_expression();
    _ctx->stop = _input->LT(-1);
    setState(309);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ArgumentAppendContext>(_tracker.createInstance<ArgumentsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleArguments);
        setState(304);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(305);
        match(CSubsetParser::COMMA);
        setState(306);
        logic_expression(); 
      }
      setState(311);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CSubsetParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 9: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 10: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 17: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 18: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 22: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubsetParser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void CSubsetParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csubsetParserInitialize();
#else
  ::antlr4::internal::call_once(csubsetParserOnceFlag, csubsetParserInitialize);
#endif
}
