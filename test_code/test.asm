.NMI    lda #$8
    pha
    pla
    sta $2000
    lda #$6
    pha
    pla
    sta $2001
    lda #$3f
    pha
    pla
    sta $2006
    lda #$0
    pha
    pla
    sta $2006
    lda #$0
    pha
    pla
    sta $2007
    lda #$23
    pha
    pla
    sta $2007
    lda #$32
    pha
    pla
    sta $2007
    lda #$f
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$36
    pha
    pla
    sta $2007
    lda #$5
    pha
    pla
    sta $2007
    lda #$f
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$23
    pha
    pla
    sta $2007
    lda #$36
    pha
    pla
    sta $2007
    lda #$f
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$20
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$0
    pha
    pla
    sta $2007
    lda #$20
    pha
    pla
    sta $2006
    lda #$0
    pha
    pla
    sta $2006
.9069_WHILE_begin    lda $206
    pha
    lda #$64
    pha
    sec
    pla
    sta $0
    pla
    sbc $0
    bne 9156_set_1
.9156_set_0    lda #$0
    jmp 9156_sete_end
.9156_set_1    lda #$1
.9156_sete_end    pha
    pla
    sta $0
    lda $0
    beq  9069_WHILE_end
    lda $206
    pha
    pla
    sta $2007
    lda $206
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
    sta $206
    jmp 9069_WHILE_begin
.9069_WHILE_end    lda #$1e
    pha
    pla
    sta $2001
    lda #$1
    pha
    pla
    rti

.main    lda #$0
    pha
    pla
    sta $206
    lda #$80
    pha
    pla
    sta $2000
.9243_LOOP    jmp 9243_LOOP
