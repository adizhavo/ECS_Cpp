#ifndef ECSMacros_hpp
#define ECSMacros_hpp

#define CAST_COMP(index, components, Type)                                      \
static_cast<Type*>(components.at(index));                                       \

#define VECTOR_REMOVE(element, vector)                                          \
vector.erase(std::remove(vector.begin(), vector.end(), element), vector.end())  \

#define VECTOR_FOR_EACH(index, vector)                                          \
for (int index = 0; index < vector.size(); index ++)                            \

#define BUILD_FILTER(size, vector)                                              \
va_list ids;                                                                    \
va_start(ids, size);                                                            \
for(int i = 0; i < size; i ++) {                                                \
long unique_id = va_arg(ids, long);                                             \
vector.push_back(unique_id);                                                    \
}                                                                               \

#endif
