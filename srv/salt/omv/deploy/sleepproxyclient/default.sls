{% set config = salt['omv_conf.get']('conf.system.sleepproxyclient') %}

configure_sleepproxyclient:
  file.managed:
    - name: /etc/sleepproxyclient.conf
    - source:
      - salt://{{ tpldir }}/files/etc-sleepproxyclient.j2
    - template: jinja
    - context:
        config: {{ config | json }}
    - user: root
    - group: root
    - mode: 644
