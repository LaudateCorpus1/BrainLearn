﻿#ifndef _NNUE_TEST_COMMAND_H_
#define _NNUE_TEST_COMMAND_H_

// USI extended command interface for NNUE evaluation function
namespace Stockfish::Eval::NNUE {

    // USI extended command for NNUE evaluation function
    void test_command(Position& pos, std::istream& stream);

}  // namespace Stockfish::Eval::NNUE

#endif
