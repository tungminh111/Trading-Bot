#include "FileRepo.h"

namespace repo {

FileRepo::FileRepo(BalanceInfo balance_info, std::vector<OrderData> orders)
    : balance_info_(balance_info), orders_(orders){};

void FileRepo::AppendData(Kline kline){

};
}  // namespace repo
