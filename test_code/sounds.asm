.reset          lda $4015
                ora #%00000011
                sta $4015
                lda #%10000000
                sta $2000
                ldx #$00
                lda #1
                sta $0
                lda #$00
                sta $1
                lda #%10111101
                sta $2
.loop           lda #%11111101
                sta $3
                jmp loop

.mainloop       dec $0
                lda $0
                beq #$01
                rti

.sound          lda #%10111101
                sta $4000
                lda #$00
                sta $4001

                lda #60
                sta $0

                ldx $1
                lda [$02]    
                sta $4002
                lda #%00000000     
                sta $4003
                inc $1

                rti