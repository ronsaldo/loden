#ifndef LODTALK_PREPROCESSOR_HACKS_HPP
#define LODTALK_PREPROCESSOR_HACKS_HPP

// Preprocessor macros hacks
// Taken from http://stackoverflow.com/questions/7508475/is-c-preprocessor-metaprogramming-turing-complete

#define LODTALK_EMPTY()
#define LODTALK_DEFER(id) id LODTALK_EMPTY()
#define LODTALK_OBSTRUCT(...) __VA_ARGS__ LODTALK_DEFER(LODTALK_EMPTY)()
#define LODTALK_EXPAND(...) __VA_ARGS__

#define LODTALK_EVAL(...)  LODTALK_EVAL1(LODTALK_EVAL1(LODTALK_EVAL1(__VA_ARGS__)))
#define LODTALK_EVAL1(...) LODTALK_EVAL2(LODTALK_EVAL2(LODTALK_EVAL2(__VA_ARGS__)))
#define LODTALK_EVAL2(...) LODTALK_EVAL3(LODTALK_EVAL3(LODTALK_EVAL3(__VA_ARGS__)))
#define LODTALK_EVAL3(...) LODTALK_EVAL4(LODTALK_EVAL4(LODTALK_EVAL4(__VA_ARGS__)))
#define LODTALK_EVAL4(...) LODTALK_EVAL5(LODTALK_EVAL5(LODTALK_EVAL5(__VA_ARGS__)))
#define LODTALK_EVAL5(...) __VA_ARGS__

#define LODTALK_CAT(a, ...) LODTALK_PRIMITIVE_CAT(a, __VA_ARGS__)
#define LODTALK_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define LODTALK_CHECK_N(x, n, ...) n
#define LODTALK_CHECK(...) LODTALK_CHECK_N(__VA_ARGS__, 0,)

#define LODTALK_NOT(x) LODTALK_CHECK(LODTALK_PRIMITIVE_CAT(LODTALK_NOT_, x))
#define LODTALK_NOT_0 ~, 1,

#define LODTALK_COMPL(b) LODTALK_PRIMITIVE_CAT(LODTALK_COMPL_, b)
#define LODTALK_COMPL_0 1
#define LODTALK_COMPL_1 0

#define LODTALK_BOOL(x) LODTALK_COMPL(LODTALK_NOT(x))

#define LODTALK_IIF(c) LODTALK_PRIMITIVE_CAT(LODTALK_IIF_, c)
#define LODTALK_IIF_0(t, ...) __VA_ARGS__
#define LODTALK_IIF_1(t, ...) t

#define LODTALK_IF(c) LODTALK_IIF(LODTALK_BOOL(c))

#define LODTALK_EAT(...)
#define LODTALK_EXPAND(...) __VA_ARGS__
#define LODTALK_WHEN(c) LODTALK_IF(c)(LODTALK_EXPAND, LODTALK_EAT)

#define LODTALK_INC(x) LODTALK_PRIMITIVE_CAT(LODTALK_INC_, x)
#define LODTALK_DEC(x) LODTALK_PRIMITIVE_CAT(LODTALK_DEC_, x)

#define LODTALK_SUB_LOOP_INDIRECT() LODTALK_SUB_LOOP
#define LODTALK_SUB_LOOP(a, n) LODTALK_IF(n)(LODTALK_OBSTRUCT(LODTALK_SUB_LOOP_INDIRECT)()(LODTALK_DEC(a), LODTALK_DEC(n)), a)
#define LODTALK_SUB(a, n) LODTALK_EVAL(LODTALK_SUB_LOOP(a, n))

#define LODTALK_ADD_LOOP_INDIRECT() LODTALK_ADD_LOOP
#define LODTALK_ADD_LOOP(a, n) LODTALK_IF(n)(LODTALK_OBSTRUCT(LODTALK_ADD_LOOP_INDIRECT)()(LODTALK_INC(a), LODTALK_DEC(n)), a)
#define LODTALK_ADD(a, n) LODTALK_EVAL(LODTALK_ADD_LOOP(a, n))

#define LODTALK_REPEAT_COUNT(count, macro, ...) \
	LODTALK_WHEN(count) \
	( \
		LODTALK_OBSTRUCT(LODTALK_REPEAT_INDIRECT) () (LODTALK_DEC(count), macro, __VA_ARGS__) \
		LODTALK_OBSTRUCT(macro) (LODTALK_DEC(count), __VA_ARGS__) \
	)
	
#define LODTALK_REPEAT_INDIRECT() LODTALK_REPEAT_COUNT

#define LODTALK_FROM_TO(from, to, macro, ...) \
	LODTALK_REPEAT_COUNT(LODTALK_SUB(to, from), macro, from, to, __VA_ARGS__)

#define LODTALK_FROM_TO_INCLUSIVE(from, to, macro, ...) LODTALK_FROM_TO(from, LODTALK_INC(to), macro, __VA_ARGS__)

// Increment / decrement expansions
#define LODTALK_INC_0 1
#define LODTALK_INC_1 2
#define LODTALK_INC_2 3
#define LODTALK_INC_3 4
#define LODTALK_INC_4 5
#define LODTALK_INC_5 6
#define LODTALK_INC_6 7
#define LODTALK_INC_7 8
#define LODTALK_INC_8 9
#define LODTALK_INC_9 10
#define LODTALK_INC_10 11
#define LODTALK_INC_11 12
#define LODTALK_INC_12 13
#define LODTALK_INC_13 14
#define LODTALK_INC_14 15
#define LODTALK_INC_15 16
#define LODTALK_INC_16 17
#define LODTALK_INC_17 18
#define LODTALK_INC_18 19
#define LODTALK_INC_19 20
#define LODTALK_INC_20 21
#define LODTALK_INC_21 22
#define LODTALK_INC_22 23
#define LODTALK_INC_23 24
#define LODTALK_INC_24 25
#define LODTALK_INC_25 26
#define LODTALK_INC_26 27
#define LODTALK_INC_27 28
#define LODTALK_INC_28 29
#define LODTALK_INC_29 30
#define LODTALK_INC_30 31
#define LODTALK_INC_31 32
#define LODTALK_INC_32 33
#define LODTALK_INC_33 34
#define LODTALK_INC_34 35
#define LODTALK_INC_35 36
#define LODTALK_INC_36 37
#define LODTALK_INC_37 38
#define LODTALK_INC_38 39
#define LODTALK_INC_39 40
#define LODTALK_INC_40 41
#define LODTALK_INC_41 42
#define LODTALK_INC_42 43
#define LODTALK_INC_43 44
#define LODTALK_INC_44 45
#define LODTALK_INC_45 46
#define LODTALK_INC_46 47
#define LODTALK_INC_47 48
#define LODTALK_INC_48 49
#define LODTALK_INC_49 50
#define LODTALK_INC_50 51
#define LODTALK_INC_51 52
#define LODTALK_INC_52 53
#define LODTALK_INC_53 54
#define LODTALK_INC_54 55
#define LODTALK_INC_55 56
#define LODTALK_INC_56 57
#define LODTALK_INC_57 58
#define LODTALK_INC_58 59
#define LODTALK_INC_59 60
#define LODTALK_INC_60 61
#define LODTALK_INC_61 62
#define LODTALK_INC_62 63
#define LODTALK_INC_63 64
#define LODTALK_INC_64 65
#define LODTALK_INC_65 66
#define LODTALK_INC_66 67
#define LODTALK_INC_67 68
#define LODTALK_INC_68 69
#define LODTALK_INC_69 70
#define LODTALK_INC_70 71
#define LODTALK_INC_71 72
#define LODTALK_INC_72 73
#define LODTALK_INC_73 74
#define LODTALK_INC_74 75
#define LODTALK_INC_75 76
#define LODTALK_INC_76 77
#define LODTALK_INC_77 78
#define LODTALK_INC_78 79
#define LODTALK_INC_79 80
#define LODTALK_INC_80 81
#define LODTALK_INC_81 82
#define LODTALK_INC_82 83
#define LODTALK_INC_83 84
#define LODTALK_INC_84 85
#define LODTALK_INC_85 86
#define LODTALK_INC_86 87
#define LODTALK_INC_87 88
#define LODTALK_INC_88 89
#define LODTALK_INC_89 90
#define LODTALK_INC_90 91
#define LODTALK_INC_91 92
#define LODTALK_INC_92 93
#define LODTALK_INC_93 94
#define LODTALK_INC_94 95
#define LODTALK_INC_95 96
#define LODTALK_INC_96 97
#define LODTALK_INC_97 98
#define LODTALK_INC_98 99
#define LODTALK_INC_99 100
#define LODTALK_INC_100 101
#define LODTALK_INC_101 102
#define LODTALK_INC_102 103
#define LODTALK_INC_103 104
#define LODTALK_INC_104 105
#define LODTALK_INC_105 106
#define LODTALK_INC_106 107
#define LODTALK_INC_107 108
#define LODTALK_INC_108 109
#define LODTALK_INC_109 110
#define LODTALK_INC_110 111
#define LODTALK_INC_111 112
#define LODTALK_INC_112 113
#define LODTALK_INC_113 114
#define LODTALK_INC_114 115
#define LODTALK_INC_115 116
#define LODTALK_INC_116 117
#define LODTALK_INC_117 118
#define LODTALK_INC_118 119
#define LODTALK_INC_119 120
#define LODTALK_INC_120 121
#define LODTALK_INC_121 122
#define LODTALK_INC_122 123
#define LODTALK_INC_123 124
#define LODTALK_INC_124 125
#define LODTALK_INC_125 126
#define LODTALK_INC_126 127
#define LODTALK_INC_127 128
#define LODTALK_INC_128 129
#define LODTALK_INC_129 130
#define LODTALK_INC_130 131
#define LODTALK_INC_131 132
#define LODTALK_INC_132 133
#define LODTALK_INC_133 134
#define LODTALK_INC_134 135
#define LODTALK_INC_135 136
#define LODTALK_INC_136 137
#define LODTALK_INC_137 138
#define LODTALK_INC_138 139
#define LODTALK_INC_139 140
#define LODTALK_INC_140 141
#define LODTALK_INC_141 142
#define LODTALK_INC_142 143
#define LODTALK_INC_143 144
#define LODTALK_INC_144 145
#define LODTALK_INC_145 146
#define LODTALK_INC_146 147
#define LODTALK_INC_147 148
#define LODTALK_INC_148 149
#define LODTALK_INC_149 150
#define LODTALK_INC_150 151
#define LODTALK_INC_151 152
#define LODTALK_INC_152 153
#define LODTALK_INC_153 154
#define LODTALK_INC_154 155
#define LODTALK_INC_155 156
#define LODTALK_INC_156 157
#define LODTALK_INC_157 158
#define LODTALK_INC_158 159
#define LODTALK_INC_159 160
#define LODTALK_INC_160 161
#define LODTALK_INC_161 162
#define LODTALK_INC_162 163
#define LODTALK_INC_163 164
#define LODTALK_INC_164 165
#define LODTALK_INC_165 166
#define LODTALK_INC_166 167
#define LODTALK_INC_167 168
#define LODTALK_INC_168 169
#define LODTALK_INC_169 170
#define LODTALK_INC_170 171
#define LODTALK_INC_171 172
#define LODTALK_INC_172 173
#define LODTALK_INC_173 174
#define LODTALK_INC_174 175
#define LODTALK_INC_175 176
#define LODTALK_INC_176 177
#define LODTALK_INC_177 178
#define LODTALK_INC_178 179
#define LODTALK_INC_179 180
#define LODTALK_INC_180 181
#define LODTALK_INC_181 182
#define LODTALK_INC_182 183
#define LODTALK_INC_183 184
#define LODTALK_INC_184 185
#define LODTALK_INC_185 186
#define LODTALK_INC_186 187
#define LODTALK_INC_187 188
#define LODTALK_INC_188 189
#define LODTALK_INC_189 190
#define LODTALK_INC_190 191
#define LODTALK_INC_191 192
#define LODTALK_INC_192 193
#define LODTALK_INC_193 194
#define LODTALK_INC_194 195
#define LODTALK_INC_195 196
#define LODTALK_INC_196 197
#define LODTALK_INC_197 198
#define LODTALK_INC_198 199
#define LODTALK_INC_199 200
#define LODTALK_INC_200 201
#define LODTALK_INC_201 202
#define LODTALK_INC_202 203
#define LODTALK_INC_203 204
#define LODTALK_INC_204 205
#define LODTALK_INC_205 206
#define LODTALK_INC_206 207
#define LODTALK_INC_207 208
#define LODTALK_INC_208 209
#define LODTALK_INC_209 210
#define LODTALK_INC_210 211
#define LODTALK_INC_211 212
#define LODTALK_INC_212 213
#define LODTALK_INC_213 214
#define LODTALK_INC_214 215
#define LODTALK_INC_215 216
#define LODTALK_INC_216 217
#define LODTALK_INC_217 218
#define LODTALK_INC_218 219
#define LODTALK_INC_219 220
#define LODTALK_INC_220 221
#define LODTALK_INC_221 222
#define LODTALK_INC_222 223
#define LODTALK_INC_223 224
#define LODTALK_INC_224 225
#define LODTALK_INC_225 226
#define LODTALK_INC_226 227
#define LODTALK_INC_227 228
#define LODTALK_INC_228 229
#define LODTALK_INC_229 230
#define LODTALK_INC_230 231
#define LODTALK_INC_231 232
#define LODTALK_INC_232 233
#define LODTALK_INC_233 234
#define LODTALK_INC_234 235
#define LODTALK_INC_235 236
#define LODTALK_INC_236 237
#define LODTALK_INC_237 238
#define LODTALK_INC_238 239
#define LODTALK_INC_239 240
#define LODTALK_INC_240 241
#define LODTALK_INC_241 242
#define LODTALK_INC_242 243
#define LODTALK_INC_243 244
#define LODTALK_INC_244 245
#define LODTALK_INC_245 246
#define LODTALK_INC_246 247
#define LODTALK_INC_247 248
#define LODTALK_INC_248 249
#define LODTALK_INC_249 250
#define LODTALK_INC_250 251
#define LODTALK_INC_251 252
#define LODTALK_INC_252 253
#define LODTALK_INC_253 254
#define LODTALK_INC_254 255
#define LODTALK_INC_255 256

#define LODTALK_DEC_1 0
#define LODTALK_DEC_2 1
#define LODTALK_DEC_3 2
#define LODTALK_DEC_4 3
#define LODTALK_DEC_5 4
#define LODTALK_DEC_6 5
#define LODTALK_DEC_7 6
#define LODTALK_DEC_8 7
#define LODTALK_DEC_9 8
#define LODTALK_DEC_10 9
#define LODTALK_DEC_11 10
#define LODTALK_DEC_12 11
#define LODTALK_DEC_13 12
#define LODTALK_DEC_14 13
#define LODTALK_DEC_15 14
#define LODTALK_DEC_16 15
#define LODTALK_DEC_17 16
#define LODTALK_DEC_18 17
#define LODTALK_DEC_19 18
#define LODTALK_DEC_20 19
#define LODTALK_DEC_21 20
#define LODTALK_DEC_22 21
#define LODTALK_DEC_23 22
#define LODTALK_DEC_24 23
#define LODTALK_DEC_25 24
#define LODTALK_DEC_26 25
#define LODTALK_DEC_27 26
#define LODTALK_DEC_28 27
#define LODTALK_DEC_29 28
#define LODTALK_DEC_30 29
#define LODTALK_DEC_31 30
#define LODTALK_DEC_32 31
#define LODTALK_DEC_33 32
#define LODTALK_DEC_34 33
#define LODTALK_DEC_35 34
#define LODTALK_DEC_36 35
#define LODTALK_DEC_37 36
#define LODTALK_DEC_38 37
#define LODTALK_DEC_39 38
#define LODTALK_DEC_40 39
#define LODTALK_DEC_41 40
#define LODTALK_DEC_42 41
#define LODTALK_DEC_43 42
#define LODTALK_DEC_44 43
#define LODTALK_DEC_45 44
#define LODTALK_DEC_46 45
#define LODTALK_DEC_47 46
#define LODTALK_DEC_48 47
#define LODTALK_DEC_49 48
#define LODTALK_DEC_50 49
#define LODTALK_DEC_51 50
#define LODTALK_DEC_52 51
#define LODTALK_DEC_53 52
#define LODTALK_DEC_54 53
#define LODTALK_DEC_55 54
#define LODTALK_DEC_56 55
#define LODTALK_DEC_57 56
#define LODTALK_DEC_58 57
#define LODTALK_DEC_59 58
#define LODTALK_DEC_60 59
#define LODTALK_DEC_61 60
#define LODTALK_DEC_62 61
#define LODTALK_DEC_63 62
#define LODTALK_DEC_64 63
#define LODTALK_DEC_65 64
#define LODTALK_DEC_66 65
#define LODTALK_DEC_67 66
#define LODTALK_DEC_68 67
#define LODTALK_DEC_69 68
#define LODTALK_DEC_70 69
#define LODTALK_DEC_71 70
#define LODTALK_DEC_72 71
#define LODTALK_DEC_73 72
#define LODTALK_DEC_74 73
#define LODTALK_DEC_75 74
#define LODTALK_DEC_76 75
#define LODTALK_DEC_77 76
#define LODTALK_DEC_78 77
#define LODTALK_DEC_79 78
#define LODTALK_DEC_80 79
#define LODTALK_DEC_81 80
#define LODTALK_DEC_82 81
#define LODTALK_DEC_83 82
#define LODTALK_DEC_84 83
#define LODTALK_DEC_85 84
#define LODTALK_DEC_86 85
#define LODTALK_DEC_87 86
#define LODTALK_DEC_88 87
#define LODTALK_DEC_89 88
#define LODTALK_DEC_90 89
#define LODTALK_DEC_91 90
#define LODTALK_DEC_92 91
#define LODTALK_DEC_93 92
#define LODTALK_DEC_94 93
#define LODTALK_DEC_95 94
#define LODTALK_DEC_96 95
#define LODTALK_DEC_97 96
#define LODTALK_DEC_98 97
#define LODTALK_DEC_99 98
#define LODTALK_DEC_100 99
#define LODTALK_DEC_101 100
#define LODTALK_DEC_102 101
#define LODTALK_DEC_103 102
#define LODTALK_DEC_104 103
#define LODTALK_DEC_105 104
#define LODTALK_DEC_106 105
#define LODTALK_DEC_107 106
#define LODTALK_DEC_108 107
#define LODTALK_DEC_109 108
#define LODTALK_DEC_110 109
#define LODTALK_DEC_111 110
#define LODTALK_DEC_112 111
#define LODTALK_DEC_113 112
#define LODTALK_DEC_114 113
#define LODTALK_DEC_115 114
#define LODTALK_DEC_116 115
#define LODTALK_DEC_117 116
#define LODTALK_DEC_118 117
#define LODTALK_DEC_119 118
#define LODTALK_DEC_120 119
#define LODTALK_DEC_121 120
#define LODTALK_DEC_122 121
#define LODTALK_DEC_123 122
#define LODTALK_DEC_124 123
#define LODTALK_DEC_125 124
#define LODTALK_DEC_126 125
#define LODTALK_DEC_127 126
#define LODTALK_DEC_128 127
#define LODTALK_DEC_129 128
#define LODTALK_DEC_130 129
#define LODTALK_DEC_131 130
#define LODTALK_DEC_132 131
#define LODTALK_DEC_133 132
#define LODTALK_DEC_134 133
#define LODTALK_DEC_135 134
#define LODTALK_DEC_136 135
#define LODTALK_DEC_137 136
#define LODTALK_DEC_138 137
#define LODTALK_DEC_139 138
#define LODTALK_DEC_140 139
#define LODTALK_DEC_141 140
#define LODTALK_DEC_142 141
#define LODTALK_DEC_143 142
#define LODTALK_DEC_144 143
#define LODTALK_DEC_145 144
#define LODTALK_DEC_146 145
#define LODTALK_DEC_147 146
#define LODTALK_DEC_148 147
#define LODTALK_DEC_149 148
#define LODTALK_DEC_150 149
#define LODTALK_DEC_151 150
#define LODTALK_DEC_152 151
#define LODTALK_DEC_153 152
#define LODTALK_DEC_154 153
#define LODTALK_DEC_155 154
#define LODTALK_DEC_156 155
#define LODTALK_DEC_157 156
#define LODTALK_DEC_158 157
#define LODTALK_DEC_159 158
#define LODTALK_DEC_160 159
#define LODTALK_DEC_161 160
#define LODTALK_DEC_162 161
#define LODTALK_DEC_163 162
#define LODTALK_DEC_164 163
#define LODTALK_DEC_165 164
#define LODTALK_DEC_166 165
#define LODTALK_DEC_167 166
#define LODTALK_DEC_168 167
#define LODTALK_DEC_169 168
#define LODTALK_DEC_170 169
#define LODTALK_DEC_171 170
#define LODTALK_DEC_172 171
#define LODTALK_DEC_173 172
#define LODTALK_DEC_174 173
#define LODTALK_DEC_175 174
#define LODTALK_DEC_176 175
#define LODTALK_DEC_177 176
#define LODTALK_DEC_178 177
#define LODTALK_DEC_179 178
#define LODTALK_DEC_180 179
#define LODTALK_DEC_181 180
#define LODTALK_DEC_182 181
#define LODTALK_DEC_183 182
#define LODTALK_DEC_184 183
#define LODTALK_DEC_185 184
#define LODTALK_DEC_186 185
#define LODTALK_DEC_187 186
#define LODTALK_DEC_188 187
#define LODTALK_DEC_189 188
#define LODTALK_DEC_190 189
#define LODTALK_DEC_191 190
#define LODTALK_DEC_192 191
#define LODTALK_DEC_193 192
#define LODTALK_DEC_194 193
#define LODTALK_DEC_195 194
#define LODTALK_DEC_196 195
#define LODTALK_DEC_197 196
#define LODTALK_DEC_198 197
#define LODTALK_DEC_199 198
#define LODTALK_DEC_200 199
#define LODTALK_DEC_201 200
#define LODTALK_DEC_202 201
#define LODTALK_DEC_203 202
#define LODTALK_DEC_204 203
#define LODTALK_DEC_205 204
#define LODTALK_DEC_206 205
#define LODTALK_DEC_207 206
#define LODTALK_DEC_208 207
#define LODTALK_DEC_209 208
#define LODTALK_DEC_210 209
#define LODTALK_DEC_211 210
#define LODTALK_DEC_212 211
#define LODTALK_DEC_213 212
#define LODTALK_DEC_214 213
#define LODTALK_DEC_215 214
#define LODTALK_DEC_216 215
#define LODTALK_DEC_217 216
#define LODTALK_DEC_218 217
#define LODTALK_DEC_219 218
#define LODTALK_DEC_220 219
#define LODTALK_DEC_221 220
#define LODTALK_DEC_222 221
#define LODTALK_DEC_223 222
#define LODTALK_DEC_224 223
#define LODTALK_DEC_225 224
#define LODTALK_DEC_226 225
#define LODTALK_DEC_227 226
#define LODTALK_DEC_228 227
#define LODTALK_DEC_229 228
#define LODTALK_DEC_230 229
#define LODTALK_DEC_231 230
#define LODTALK_DEC_232 231
#define LODTALK_DEC_233 232
#define LODTALK_DEC_234 233
#define LODTALK_DEC_235 234
#define LODTALK_DEC_236 235
#define LODTALK_DEC_237 236
#define LODTALK_DEC_238 237
#define LODTALK_DEC_239 238
#define LODTALK_DEC_240 239
#define LODTALK_DEC_241 240
#define LODTALK_DEC_242 241
#define LODTALK_DEC_243 242
#define LODTALK_DEC_244 243
#define LODTALK_DEC_245 244
#define LODTALK_DEC_246 245
#define LODTALK_DEC_247 246
#define LODTALK_DEC_248 247
#define LODTALK_DEC_249 248
#define LODTALK_DEC_250 249
#define LODTALK_DEC_251 250
#define LODTALK_DEC_252 251
#define LODTALK_DEC_253 252
#define LODTALK_DEC_254 253
#define LODTALK_DEC_255 254
#define LODTALK_DEC_256 255

#endif //LODTALK_PREPROCESSOR_HACKS_HPP