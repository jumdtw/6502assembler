.reset          lda $4015
                ora #%00000111
                sta $4015

                                                    
                lda #%10111101
                sta $4000
                lda #$00
                sta $4001

.sound          lda #$9f    
                sta $4002   
                lda #%00000000     
                sta $4003

                lda #$6000
                sta $0
                jsr delay_30

.lala           lda #$70    
                sta $4002   
                lda #%00000000     
                sta $4003
.now            jmp now

.delay_30       dec $0
                lda $0
                beq #$03
                jmp delay_30
.return_delay   rts