.NMI    ldx $249
    lda [#$0]
    pha
    pla
    sta $24a
    lda $24a
    pha
    lda #$0
    pha
    sec
    pla
    sta $0
    pla
    sbc $0
    bne 17218_set_1
.17218_set_0    lda #$0
    jmp 17218_sete_end
.17218_set_1    lda #$1
.17218_sete_end    pha
    pla
    sta $0
    lda $0
    beq  7218end
    ldx $249
    lda [#$0]
    pha
    lda #$1
    pha
    sec
    pla
    sta $0
    pla
    sbc $0
    pha
    pla
    ldx $249
    sta [#$00]
    lda #$1
    pha
    pla
    rti
.7218end    lda $248
    pha
    pla
    sta $0
    ldx $0
    lda [#$206]
    pha
    pla
    sta $4000
    lda $248
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $248
    lda $248
    pha
    pla
    sta $0
    ldx $0
    lda [#$206]
    pha
    pla
    sta $4002
    lda $248
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $248
    lda $248
    pha
    pla
    sta $0
    ldx $0
    lda [#$206]
    pha
    pla
    sta $4003
    lda $248
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $248
    lda $248
    pha
    pla
    sta $0
    ldx $0
    lda [#$206]
    pha
    pla
    sta $4006
    lda $248
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $248
    lda $248
    pha
    pla
    sta $0
    ldx $0
    lda [#$206]
    pha
    pla
    sta $400a
    lda $248
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $248
    lda $248
    pha
    pla
    sta $0
    ldx $0
    lda [#$206]
    pha
    pla
    sta $1
    lda $248
    pha
    lda #$1
    pha
    clc
    pla
    sta $0
    pla
    adc $0
    pha
    pla
    sta $248
    lda $248
    pha
    lda #$fc
    pha
    sec
    pla
    sta $0
    pla
    sbc $0
    beq 17218_set_1
.17218_set_0    lda #$0
    pha
    jmp 17218_sete_end.17218_set_1    lda #$1
    pha
.17218_sete_end    pha
    pla
    sta $0
    lda $0
    beq  7218end
    lda #$0
    pha
    pla
    sta $248
.7218end    lda #$1
    pha
    pla
    rti

.main    lda #$7
    pha
    pla
    sta $4015
    lda #$a7
    pha
    pla
    sta $4000
    lda #$0
    pha
    pla
    sta $4001
    lda #$a7
    pha
    pla
    sta $4004
    lda #$0
    pha
    pla
    sta $4005
    lda #$0
    pha
    pla
    sta $4007
    lda #$ff
    pha
    pla
    sta $4008
    lda #$0
    pha
    pla
    sta $400b
    lda #$af
    pha
    lda #$1d
    pha
    lda #$1
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$af
    pha
    lda #$1d
    pha
    lda #$1
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$af
    pha
    lda #$fe
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$af
    pha
    lda #$fe
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$af
    pha
    lda #$aa
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$af
    pha
    lda #$aa
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$af
    pha
    lda #$87
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$af
    pha
    lda #$87
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$0
    pha
    lda #$e
    pha
    lda #$af
    pha
    lda #$71
    pha
    lda #$0
    pha
    lda #$e2
    pha
    lda #$0
    pha
    lda #$14
    pha
    lda #$a7
    pha
    lda #$71
    pha
    lda #$0
    pha
    lda #$e2
    pha
    lda #$0
    pha
    lda #$a
    pha
    lda #$af
    pha
    lda #$c7
    pha
    lda #$1
    pha
    lda #$e2
    pha
    lda #$0
    pha
    lda #$37
    pha
    pla
    sta $247
    pla
    sta $246
    pla
    sta $245
    pla
    sta $244
    pla
    sta $243
    pla
    sta $242
    pla
    sta $241
    pla
    sta $240
    pla
    sta $23f
    pla
    sta $23e
    pla
    sta $23d
    pla
    sta $23c
    pla
    sta $23b
    pla
    sta $23a
    pla
    sta $239
    pla
    sta $238
    pla
    sta $237
    pla
    sta $236
    pla
    sta $235
    pla
    sta $234
    pla
    sta $233
    pla
    sta $232
    pla
    sta $231
    pla
    sta $230
    pla
    sta $22f
    pla
    sta $22e
    pla
    sta $22d
    pla
    sta $22c
    pla
    sta $22b
    pla
    sta $22a
    pla
    sta $229
    pla
    sta $228
    pla
    sta $227
    pla
    sta $226
    pla
    sta $225
    pla
    sta $224
    pla
    sta $223
    pla
    sta $222
    pla
    sta $221
    pla
    sta $220
    pla
    sta $21f
    pla
    sta $21e
    pla
    sta $21d
    pla
    sta $21c
    pla
    sta $21b
    pla
    sta $21a
    pla
    sta $219
    pla
    sta $218
    pla
    sta $217
    pla
    sta $216
    pla
    sta $215
    pla
    sta $214
    pla
    sta $213
    pla
    sta $212
    pla
    sta $211
    pla
    sta $210
    pla
    sta $20f
    pla
    sta $20e
    pla
    sta $20d
    pla
    sta $20c
    pla
    sta $20b
    pla
    sta $20a
    pla
    sta $209
    pla
    sta $208
    pla
    sta $207
    pla
    sta $206
    lda #$0
    pha
    pla
    sta $248
    lda #$1
    pha
    pla
    sta $249
    lda #$14
    pha
    pla
    ldx $249
    sta [#$00]
    lda #$0
    pha
    pla
    sta $24a
    lda #$80
    pha
    pla
    sta $2000
.7222_WHILE_begin    jmp 7222_WHILE_begin