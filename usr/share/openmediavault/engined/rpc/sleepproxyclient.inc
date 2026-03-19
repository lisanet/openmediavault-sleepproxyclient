<?php
/**
 * @license   MIT
 * @author    Simone Karin Lehmann
 */


class OMVRpcServiceSleepProxyClient extends \OMV\Rpc\ServiceAbstract
{

    public function getName()
    {
        return 'SleepProxyClient';
    }

    public function initialize()
    {
        $this->registerMethod('getSettings');
        $this->registerMethod('setSettings');
    }

    public function getSettings($params, $context)
    {
        // Validate the RPC caller context.
        $this->validateMethodContext($context, ["role" => OMV_ROLE_ADMINISTRATOR]);
        // Get the configuration object.
        $db = \OMV\Config\Database::getInstance();
        $object = $db->get("conf.system.sleepproxyclient");
        return $object->getAssoc();
    }

    public function setSettings($params, $context)
    {
        // Validate the RPC caller context.
        $this->validateMethodContext($context, ["role" => OMV_ROLE_ADMINISTRATOR]);
        // Validate the parameters of the RPC service method.
        $this->validateMethodParams($params, "rpc.sleepproxyclient.setsettings");
        // Get the existing configuration object.
        $db = \OMV\Config\Database::getInstance();
        $object = $db->get("conf.system.sleepproxyclient");
        $object->setAssoc($params);
        $db->set($object);
        return $object->getAssoc();
    }

}
