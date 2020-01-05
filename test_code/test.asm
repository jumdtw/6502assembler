.main    lda $200
    pha
    lda #$a
    pha
    pla
    sta $200
    lda $200
    sta $0
    ldx $0
    lda #$1
    pha
    pla
    sta [#$00]
        lda $a
        sta $4015
        lda #%10100111                        
        sta $4000	                       
        lda #$00                              
        sta $4001
        lda #$aa
        sta $4002
        lda #$00
        sta $4003