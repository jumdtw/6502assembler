.reset          lda #%00000111
                sta $4015

                lda #%10000000
                sta $2000

                lda #%10100111                        
                sta $4000	                       
                lda #$00                              
                sta $4001	                       
                lda #%10100111                            
                sta $4004		                        
                lda #$00                                  
                sta $4005	                            
                lda #$ff                                   
                sta $4008        

                lda #60
                sta $0
                lda #$02
                sta $1






;--------------------------------start   1-1------------------------------------------
; sound info set 
            ;ch1 Decline
                lda #%10101111 
                sta $2
            ;ch1 sound low
                lda #$1d
                sta $3
            ;ch1 sound high
                lda #$01
                sta $4
            ;ch2 sound low (ch2 is only low)
                lda #$00
                sta $5
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $6
            ;delay time 
                lda #14
                sta $7

            ;ch1 Decline
                lda #%10101111 
                sta $8
            ;ch1 sound low
                lda #$1d
                sta $9
            ;ch1 sound high
                lda #$01
                sta $a
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $b
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $c
            ;delay time
                lda #14
                sta $d 

            ;ch1 Decline
                lda #%10101111 
                sta $e
            ;ch1 sound low
                lda #$fe
                sta $f
            ;ch1 sound high
                lda #$00
                sta $10
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $11
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $12
            ;delay time
                lda #14
                sta $13

            ;ch1 Decline
                lda #%10101111 
                sta $14
            ;ch1 sound low
                lda #$fe
                sta $15
            ;ch1 sound high
                lda #$00
                sta $16
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $17
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $18
            ;delay time
                lda #14
                sta $19




            ;ch1 Decline
                lda #%10101111 
                sta $1a
            ;ch1 sound low
                lda #$aa
                sta $1b
            ;ch1 sound high
                lda #$00
                sta $1c
            ;ch2 sound low (ch2 is only low)
                lda #$00
                sta $1d
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $1e
            ;delay time 
                lda #14
                sta $1f

            ;ch1 Decline
                lda #%10101111 
                sta $20
            ;ch1 sound low
                lda #$aa
                sta $21
            ;ch1 sound high
                lda #$00
                sta $22
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $23
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $24
            ;delay time
                lda #14
                sta $25 

            ;ch1 Decline
                lda #%10101111 
                sta $26
            ;ch1 sound low
                lda #$87
                sta $27
            ;ch1 sound high
                lda #$00
                sta $28
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $29
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $2a
            ;delay time
                lda #14
                sta $2b

            ;ch1 Decline
                lda #%10101111 
                sta $2c
            ;ch1 sound low
                lda #$87
                sta $2d
            ;ch1 sound high
                lda #$00
                sta $2e
            ;ch2 sound low (ch2 is only low)
                lda #$00
                sta $2f
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $30
            ;delay time 
                lda #14
                sta $31

            

;--------------------------------end   1-1------------------------------------------


;--------------------------------start   1-2------------------------------------------
; sound info set 
            ;ch1 Decline
                lda #%10101111 
                sta $32
            ;ch1 sound low
                lda #$71
                sta $33
            ;ch1 sound high
                lda #$00
                sta $34
            ;ch2 sound low (ch2 is only low)
                lda #$e2
                sta $35
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $36
            ;delay time 
                lda #20
                sta $37

            ;ch1 Decline
                lda #%10100111 
                sta $38
            ;ch1 sound low
                lda #$71
                sta $39
            ;ch1 sound high
                lda #$00
                sta $3a
            ;ch2 sound low (ch2 is only low) 
                lda #$e2
                sta $3b
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $3c
            ;delay time
                lda #10
                sta $3d

            ;ch1 Decline
                lda #%10101111 
                sta $3e
            ;ch1 sound low
                lda #$c7
                sta $3f
            ;ch1 sound high
                lda #$01
                sta $40
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $41
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $42
            ;delay time
                lda #55
                sta $43

         
;--------------------------------end   1-2------------------------------------------



;--------------------------------start   1-3------------------------------------------
; sound info set 
            ;ch1 Decline
                lda #%10100111 
                sta $44
            ;ch1 sound low
                lda #$ca
                sta $45
            ;ch1 sound high
                lda #$00
                sta $46
            ;ch2 sound low (ch2 is only low)
                lda #$aa
                sta $47
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $48
            ;delay time 
                lda #20
                sta $49

            ;ch1 Decline
                lda #%10100111 
                sta $4a
            ;ch1 sound low
                lda #$fd
                sta $4b
            ;ch1 sound high
                lda #$01
                sta $4c
            ;ch2 sound low (ch2 is only low) 
                lda #$7f
                sta $4d
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $4e
            ;delay time
                lda #20
                sta $4f

            ;ch1 Decline
                lda #%10100111 
                sta $50
            ;ch1 sound low
                lda #$87
                sta $51
            ;ch1 sound high
                lda #$00
                sta $52
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $53
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $54
            ;delay time
                lda #20
                sta $55

            ;ch1 Decline
                lda #%10100111 
                sta $56
            ;ch1 sound low
                lda #$7f
                sta $57
            ;ch1 sound high
                lda #$00
                sta $58
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $59
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $5a
            ;delay time
                lda #15
                sta $5b

            ;ch1 Decline
                lda #%10101111 
                sta $5c
            ;ch1 sound low
                lda #$aa
                sta $5d
            ;ch1 sound high
                lda #$00
                sta $5e
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $5f
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $60
            ;delay time
                lda #30
                sta $61 
;--------------------------------end   1-3------------------------------------------

;--------------------------------start   1-4------------------------------------------
; sound info set 
            ;ch1 Decline
                lda #%10100111 
                sta $62
            ;ch1 sound low
                lda #ca
                sta $63
            ;ch1 sound high
                lda #$00
                sta $64
            ;ch2 sound low (ch2 is only low)
                lda #$aa
                sta $65
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $66
            ;delay time 
                lda #20
                sta $67

            ;ch1 Decline
                lda #%10100111 
                sta $68
            ;ch1 sound low
                lda #$00
                sta $69
            ;ch1 sound high
                lda #$00
                sta $6a
            ;ch2 sound low (ch2 is only low) 
                lda #$7f
                sta $6b
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $6c
            ;delay time
                lda #20
                sta $6d 

            ;ch1 Decline
                lda #%10100111 
                sta $6e
            ;ch1 sound low
                lda #$87
                sta $6f
            ;ch1 sound high
                lda #$00
                sta $70
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $71
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $72
            ;delay time
                lda #20
                sta $73

            ;ch1 Decline
                lda #%10100111 
                sta $74
            ;ch1 sound low
                lda #$7f
                sta $75
            ;ch1 sound high
                lda #$00
                sta $76
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $77
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $78
            ;delay time
                lda #15
                sta $79

            ;ch1 Decline
                lda #%10100011 
                sta $7a
            ;ch1 sound low
                lda #$aa
                sta $7b
            ;ch1 sound high
                lda #$00
                sta $7c
            ;ch2 sound low (ch2 is only low) 
                lda #$00
                sta $7d
            ;Twave sound low (Twave is only low)
                lda #$00
                sta $7e
            ;delay time
                lda #17
                sta $7f
;--------------------------------end   1-4------------------------------------------

.loop           jmp loop

; $0 == delay
; beqなどのブランチで飛ぶ時のオフセットは実行したい命令のメモリ位置ー１byte！！！

.mainloop       dec $0
                lda $0
                beq sound ; ここ書き換えたから音ならなかったらこれのせい
                rti

            ;ch1 Decline
.sound          ldx $1
                lda [#$00]                       
                sta $4000
                inc $1

            ;ch1 sound low
                ldx $1
                lda [#$00]
                sta $4002
                inc $1

            ;ch1 sound high
                ldx $1
                lda [#$00]     
                sta $4003
                inc $1

            ;ch2 sound low (ch2 is only low)
                ldx $1
                lda [#$00] 
                sta $4006
                lda #$00 
                sta $4007
                inc $1

            ;Twave sound low (Twave is only low)
                ldx $1
                lda [#$00]   
                sta $400a
                lda #$00    
                sta $400b
                inc $1

            ;delay time 
                ldx $1
                lda [#$00]
                sta $0
                inc $1

                rti