/* Copyright (c) 2021, Qihoo, Inc.  All rights reserved.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 ==============================================================================*/

#ifndef CORE_OPERATORS_ONE_HOT_H_
#define CORE_OPERATORS_ONE_HOT_H_
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "core/operands/variable.h"
#include "core/operators/unary_operator.h"
namespace clink {
class OneHot : public UnaryOperator {
 public:
  OneHot();

  OneHot(const std::string& feature_name, const OpParamMap& param_map);

  const Feature* Evaluate(Context*) override;

  std::shared_ptr<BaseOperator> Clone() const override;

  bool ParseParamMap(const std::string& name,
                     const OpParamMap& param_map) override;

  bool ParseParamMap(const std::vector<std::string>& variables,
                     const OpParamMap& param_map) override;

 private:
  int bin_size_;
  std::unordered_map<std::string, int> encode_map_;
  bool ParseParam(const std::string& name, const OpParamMap& param_map);
};
}  // namespace clink

#endif  // CORE_OPERATORS_ONE_HOT_H_
