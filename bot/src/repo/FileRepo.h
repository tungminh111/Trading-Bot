#ifndef FILE_REPO
#define FILE_REPO

#include "entity/Action.h"
#include "entity/BalanceInfo.h"
#include "entity/Kline.h"
#include "util/String.h"
#include <vector>

namespace repo {
class FileRepo {
   public:
    explicit FileRepo(BalanceInfo balance_info, std::vector<OrderData> orders);

    void AppendData(Kline kline);
    void AppendAction(OrderData action);

    BalanceInfo GetBalanceInfo();

    std::string DebugMsg() const {
        return util::string::FormatString("{\"balance_info_\": \"%s\"}",
                                          balance_info_.DebugMsg().c_str());
    }

   private:
    BalanceInfo balance_info_;
    std::vector<OrderData> orders_;
};
}  // namespace repo

#endif
